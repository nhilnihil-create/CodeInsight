#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

ll dp[110000][2];//dp[i][j]=j flag i桁 (a+b==lか） a+b==a^b 
int main(){cout<<fixed<<setprecision(20);
		   //桁dp?
           //1なら
           string s;
           cin>>s;
           int n=s.size();
           dp[0][0]=1;
           rep(i,1,n+1){
             int g=s[i-1]-'0';
             //0>0
             if(g==0){
               dp[i][0]+=dp[i-1][0];
             }
             else{
               dp[i][0]+=dp[i-1][0]*2;
             }
             //0>1
             //g==1
             //i桁め^が0
             if(g==1)dp[i][1]+=dp[i-1][0];
             //1>1
             dp[i][1]+=dp[i-1][1]*3;
             rep(j,0,2)dp[i][j]%=inf;
             //cout<<dp[i][1]<<endl;
           }
           cout<<(dp[n][0]+dp[n][1])%inf<<endl;
}