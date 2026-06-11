#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	int h,w,a,b;  cin>>h>>w>>a>>b;
  int ans[h][w];
  rep(i,0,h){
    rep(j,0,w){
      if(i<b && j<a)ans[i][j]=0;
      else if(i<b || j<a)ans[i][j]=1;
      else ans[i][j]=0;
    }
  }
  rep(i,0,h){
    rep(j,0,w){
      cout<<ans[i][j];
    }
    cout<<endl;
  }

      
      
 
  
	
	
	return 0;
}