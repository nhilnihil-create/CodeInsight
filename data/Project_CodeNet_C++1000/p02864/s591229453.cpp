#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline void out(T a){ cout << a << '\n'; }
void YN(bool ok){if(ok) cout << "Yes" << endl; else cout << "No" << endl;}
//void YN(bool ok){if(ok) cout << "YES" << endl; else cout << "NO" << endl;}


const ll INF=1e18;
const int mx=200005;

ll dp[310][310];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll N,K;
    cin>>N>>K;
    ll H[N+1];
    for(int i=1;i<=N;i++) cin>>H[i];
    H[0]=0;
    for(int i=0;i<=305;i++) for(int j=0;j<=305;j++) dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=305;j++){
            for(int k=0;k<i;k++){
                chmin(dp[i][j],dp[k][j-1]+max(0LL,H[i]-H[k]));
            }
        }
    }
    ll ans=INF;
    for(int i=N-K;i<=N;i++) chmin(ans,dp[i][N-K]);
    out(ans);
}