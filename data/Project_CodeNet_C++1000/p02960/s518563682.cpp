//bit全探索
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

ll dp[110000][15];//かみi桁　あまり　通り数

int main(){cout<<fixed<<setprecision(10);
		   string s;
           cin>>s;
           int n=s.size();
           dp[0][0]=1;
           rep(i,1,n+1){
             rep(j,0,13){
              if(s[i-1]!='?'){
                //10x+s=j
                rep(k,0,13){
                  
                if((k*10+(s[i-1]-'0'))%13==j)
                dp[i][j]+=dp[i-1][k];
                }
              }
              else{
                //dp[i][j]=Σdp[i-1][k] 
                rep(k,0,10){
                  rep(l,0,13){
                    if((l*10+k)%13==j)
                  dp[i][j]+=dp[i-1][l]; 
                  }
                }
              }
               dp[i][j]%=inf;
             }
           }
           cout<<dp[n][5]<<endl;
}