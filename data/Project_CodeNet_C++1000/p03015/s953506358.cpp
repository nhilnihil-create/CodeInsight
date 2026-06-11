#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> l_l;
typedef pair<int,int> i_i;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[100100][2];

int main(){
  string s; cin >> s;
  int n=s.size();
  dp[0][0]=1;
  rep(i,n){
    if(s[i]=='1'){
      dp[i+1][0]=dp[i][0]*2%mod;
      dp[i+1][1]=(dp[i][1]*3+dp[i][0])%mod;
    }
    else{
      dp[i+1][0]=dp[i][0];
      dp[i+1][1]=dp[i][1]*3%mod;
    }
  }
  cout << (dp[n][0]+dp[n][1])%mod << endl;
}