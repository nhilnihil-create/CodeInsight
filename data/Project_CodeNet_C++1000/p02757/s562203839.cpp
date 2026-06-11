#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll mod_pow(ll x, ll n, ll mod){
    ll ret = 1;
    while(n > 0){
        if(n % 2) 
            ret *= x;
        x *= x;
        ret %= mod;
        x %= mod;
        n >>= 1;
    }
    return ret;

    //ll ret = 1;
    //while(n > 0){
    //    ret *= x;
    //    ret %= mod;
    //    n--;
    //}
    //return ret;
}


int main(){
    ll N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    ll ans = 0;
    if(P == 2){
        REP(i,N){
            int x = S[i] - '0';
            if(x % 2 == 0)
                ans += N-i;
        }
    }
    else if(P == 5){
        REP(i,N){
            int x = S[i] - '0';
            if(x % 5 == 0)
                ans += N-i;
        }
    }
    else{
        map<ll, ll> ma;
        ma[0]++;
        ll last = 0;
        REP(i,N){
            ll x = S[i] - '0';
            ll y = last + mod_pow(10, i, P) * x;
            last = y % P;
            ma[last]++;
        }

        for(auto&& p : ma)
            ans += p.second * (p.second-1) / 2;
    }


    cout << ans << endl;
    return 0;
}
