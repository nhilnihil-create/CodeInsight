#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    ll N,M;
    cin >> N >> M;
    vector<ll> dp(N+5);
    queue<ll> A;
    REP(i,M){
        ll tmp;
        cin >> tmp;
        A.push(tmp);
    }
    dp[0] = 1;
    REP(i,N){
        if(i == A.front()&&i != 0){
            A.pop();
        }else{
            dp[i+1] += dp[i];
            dp[i+2] += dp[i];
            dp[i+1]%=mod;
            dp[i+2]%=mod;
        }
    }
    cout << dp[N]%mod << "\n";
}