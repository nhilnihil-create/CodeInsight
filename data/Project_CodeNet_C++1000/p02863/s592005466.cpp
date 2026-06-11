#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n,t;
ll dp[3100][6100]; //dp[i][j]={i品目まで　食べ終わるのがj分まで の幸せの最大値}
vector<pair<ll,ll>> ab;

int main(){cout<<fixed<<setprecision(10);
		   cin>>n>>t;
           ll a,b;
           ab.resize(n+1);
           for(int i=1;i<=n;i++){
             cin>>a>>b;
             ab[i].first=a;
             ab[i].second=b;
           }
           //入力
           sort(all(ab));
           for(int i=1;i<=n;i++){
            for(int j=0;j<=t+3010;j++){
              if(i!=n){
                  dp[i][j]=dp[i-1][j];//i品目を食べない

                  if(j-ab[i].first>=0&&j-ab[i].first<t)//i品目を食べられるか
                    dp[i][j]=max(dp[i][j],dp[i-1][j-ab[i].first]+ab[i].second);//食べた
              }
              else{
                  dp[i][j]=dp[i-1][j];
                  if(j<t)dp[i][j]+=ab[i].second;
              }
            }
             
             
           }
           
           ll ans=0;
           
           rep(i,0,t+3010){
             
             ans=max(ans,dp[n][i]);
             
           }
           
           cout<<ans<<endl;
}