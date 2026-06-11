#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n,k,c; cin >> n >> k >> c;
  string s; cin >> s;
  vector<int> mxl(n+2);
  vector<int> mxr(n+2);
  rep(i,n){
    if(s[i]=='o'){
      if(i+1-(c+1)>=1) mxl[i+1]=mxl[i+1-(c+1)]+1;
      else mxl[i+1]=1;
    }
    else{
      mxl[i+1]=mxl[i];
    }
  }
  rrep(i,n){
    if(s[i]=='o'){
      if(i+1+c+1<=n) mxr[i+1]=mxr[i+1+c+1]+1;
      else mxr[i+1]=1;
    }
    else{
      mxr[i+1]=mxr[i+2];
    }
  }
  vector<int> ans(0);
  rep(i,n){
    if(mxl[i+1]>mxl[i]&&mxr[i+1]>mxr[i+2]) ans.push_back(i+1);
  }
  if(mxl[n]!=k){
    cout << endl;
    return 0;
  }
  rep(i,ans.size()){
    cout << ans[i] << endl;
  }
}