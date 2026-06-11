#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int g[1010][1010];

int main(){
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  rep(i,h){
    rep(j,w){
      if((i<b&&j<a)||(b<=i&&a<=j)) g[i][j]=1;
    }
  }
  rep(i,h){
    rep(j,w){
      cout << g[i][j];
    }cout << endl;
  }
}