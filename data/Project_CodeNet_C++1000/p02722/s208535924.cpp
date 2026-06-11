#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N;
    cin >> N;

    ll MAX = 1000005;
    vector<ll> c;
    vector<ll> d(MAX, 0);
    ll dd;
    ll ans;

    //約数列挙
    ll tmp;
    for (ll i = 2; i*i <= N; i++) {
        if(N % i == 0){
            c.push_back(i);
            if(i * i != N){
                c.push_back(N / i);
            }
        }
    }

    //素因数分解
    tmp = N - 1;
    for (ll i = 2; i < MAX; i++) {
        while(tmp % i == 0){
            d[i]++;
            tmp = tmp / i;
        }
    }
    dd = tmp;

    //N-1の約数の個数(1をのぞく)
    tmp = 1;
    if(dd != 1){
        tmp = 2;
    }
    for (ll i = 2; i < MAX; i++) {
        if(d[i] != 0){
            tmp = tmp * (d[i] + 1);
        }
    }
    ans = tmp - 1; //1を引く

    //Nの約数パート
    for (ll K : c) {
        tmp = N;
        while(tmp >= K){
            if(tmp % K == 0){
                tmp = tmp / K;
            }
            else{
                tmp = tmp % K;
            }
        }
        if(tmp == 1){
            ans++;
        }
    }
    ans++; //N自体
    printf("%lld\n", ans);
}
