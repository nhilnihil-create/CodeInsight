#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;


// 両端のXORが自身と等しいということは、両端と自身をXORすると0となる。
// xi, xi+1, xi+2, xi+3の4つの数を考える。Xi^Xi+1^xi+2 = xi+1^xi+2^xi+3よりxi=xi+3
// 3個区切りで同じ数字にする必要がある。xi+1やxi+2についても同様である。
// したがって、以下のように分類できる。
// 1. 異なる数字が4種類以上出現する場合は絶対に達成不可能
// 2. 異なる数字が3種類出現する場合は、それぞれの出現回数がn/3回ずつである
// 3. 異なる数字が2種類出現する場合は、0がn/3回、1以上の整数が2*n/3回
// 4. 0がn回出現する場合

int main(){
    Init();
    ll n; cin >> n;
    map<ll, ll> cnt;
    ll cnt_z = 0;
    rep(i, n){
        ll a; cin >> a;
        cnt[a]++;
        if(a == 0) cnt_z++;
    }
    // 上記の条件4.
    if(cnt_z == n) Yes();
    // 3の倍数じゃない場合や4種類以上の数字が出現する場合、2. 3.の達成が不可能
    else if(n%3 != 0 || cnt.size() >= 4) No();
    else{
        // 条件2.
        if(cnt.size() == 3){
            ll num = n/3;
            bool ans = true;
            ll calc = 0;
            for(auto &p: cnt){
                if(p.second != num) ans = false;
                calc ^= p.first;
            }
            if(calc) ans = false;
            ans ? Yes() : No();
        }
        // 条件3.
        else{
            ll num = n/3;
            bool ans = true;
            for(auto &p: cnt){
                if((p.first == 0 && p.second != num) || (p.first != 0 && p.second != num*2)) ans = false;
            }
            ans ? Yes() : No();
        }
    }
}