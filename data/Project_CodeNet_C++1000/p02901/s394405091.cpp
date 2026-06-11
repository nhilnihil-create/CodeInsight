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

ll dp[1005][4100];

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    ll a[m],b[m],c[m][n];
    rep(i,m){
        cin>>a[i]>>b[i];
        rep(j,b[i]){
            cin>>c[i][j];
            c[i][j]--;
        }
    }
    rep(i,m+1){
        rep(j,(1<<n)) dp[i][j]=INF;
    }
    dp[0][0]=0;
    rep(i,m){
        rep(j,(1<<n)){
            int to=j;
            ll cnt=a[i];
            rep(k,b[i]){
                int tmp=(1<<(c[i][k]));
                to|=tmp;
                //cnt+=a[i];
            }
            chmin(dp[i+1][j],dp[i][j]);
            chmin(dp[i+1][to],dp[i][j]+cnt);
        }
    }
    if(dp[m][(1<<n)-1]<INF) out(dp[m][(1<<n)-1]);
    else out(-1);
}