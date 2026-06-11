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

int main(){
  int n,k; cin >> n >> k;
  if(k>(n-1)*(n-2)/2){
    cout << -1 << endl;
    return 0;
  }
  int cnt=n-1+(n-1)*(n-2)/2-k;
  int cntt=0;
  cout << cnt << endl;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      cout << i << " " << j << endl;
      cntt++;
      if(cntt==cnt) return 0;
    }
  }
}