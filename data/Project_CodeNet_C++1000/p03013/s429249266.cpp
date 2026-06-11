#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

const ll INF = 1LL << 60;
const ll MOD = 1e9+7;

int main()
{
    int N,M;
    cin >> N >> M;
    vll dp(N+1);
    vint oks(N+1,true);
    REP(i,M){
        int a;
        cin >> a;
        oks[a] = false;
    }
    dp[0] = 1;
    for(int i=1; i<N+1; i++){
        if(oks[i]){
            dp[i] += dp[i-1];
            dp[i] %= MOD;
            if(i != 1){
                dp[i] += dp[i-2];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[N] << endl;
}