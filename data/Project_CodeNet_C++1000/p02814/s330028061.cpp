#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for(int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005
/*
step1: a が偶数列：　何回2で和れるかを調べる 個数が違ったら0 cnt 回割り切れた
    while True
step2: aが奇数列になっている。奇数列の中で、最小公倍数を求める lcm_odd
step3: lcm_odd * (2**cnt) = 最小公倍数になる
step4: (m//lcm_odd_min + 1) // 2
*/

vector<pair<ll, int>> fac;
void PrimeFactorInit(ll x){ // 素因数と個数のペアを返す.
    if(x >= 2){
        for(ll i = 2; i <= x; i++){
            if(i * i > x)break;
            if(x % i == 0){
                int cnt = 0;
                while(x % i == 0){
                    cnt++;
                    x /= i;
                }
                pair<ll, int> p;
                p.first = i;
                p.second = cnt;
                fac.push_back(p);
            }
        }
        if(x > 1){
            pair<ll, int> p;
            p.first = x;
            p.second = 1;
            fac.push_back(p);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll a[n];
    rep(i,n)cin >> a[i];

    int cnt = 0;
    int ng = 0;//ng が立っていたら揃っていない。
    while(true){
        ng = 0;
        rep(i,n){
            if(a[i] % 2 == 0){
                a[i] /= 2;
            }else{
                ng++;
                // break;
            }
        }
        if(ng >= 1){
            if(ng == n){
                ng = 0;
            }
            break;
        }
        cnt++;
    }
    cnt--;

    if(ng > 0){
        cout << 0 << endl;
        return 0;
    }

    sort(a,a+n);

    ll ans = 0;

    map<ll,ll> mp;
    ll lcm = 1;
    rep(i,cnt){
        lcm *= 2;
    }
    rep(i,n){
        if(i >= 1 && a[i] == a[i-1])continue;
        fac.clear();
        PrimeFactorInit(a[i]);
        rep(j,fac.size()){
            int tmp = fac[j].second - mp[fac[j].first];
            if(tmp > 0){
                rep(k,tmp){
                    lcm *= fac[j].first;
                    if(lcm > m){
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
            mp[fac[j].first] = max((ll)fac[j].second, mp[fac[j].first]);
        }
    }

    

    
    // cout << "OK" << endl;
    /*
    for(auto p : mp){
        rep(i,p.second){
            lcm *= p.first;
            if(lcm > m){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    */

    ans = (m/lcm + 1) / 2;

    cout << ans << endl;
    return 0;
}


