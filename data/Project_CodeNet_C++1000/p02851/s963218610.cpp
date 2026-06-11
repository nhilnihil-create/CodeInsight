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

int main(){
    ll N, K;
    cin >> N >> K;

    // N+1
    vector<ll> A;
    A.push_back(0);
    REP(i,N){
        ll a;
        cin >> a;
        A.push_back(a);
    }

    vector<ll> S(N+1);
    REP(i,N+1){
        S[i] = A[i];
        if(i > 0)
            S[i] += S[i-1];
        S[i] %= K;
    }

    vector<ll> X(N+1);
    REP(i,N+1){
        ll x = S[i] - i%K;
        X[i] = (K + x) % K;
    }

    //for(auto&& x : X)
    //    cout << x << endl;

    map<ll, ll> ma;
    REP(i,min(K,N+1)){
        ma[X[i]]++;
    }

    ll ans = 0;
    REP(i,N+1){
        ll x = X[i];
        ma[x]--;

        ll num = ma[x];
        ans += num;

        if(i + K < N+1){
            ll add = X[i+K];
            ma[add]++;
        }
    }

    cout << ans << endl;

    return 0;
}
