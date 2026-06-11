//#define _GLIBCXX_DEBUG
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

int main(){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(all(a));
  vector<pii> o(0);
  for(int i=1;i<n-1;i++){
    if(a[i]<0){
      o.push_back(pii(a[n-1],a[i]));
      a[n-1]-=a[i];
    }
    else{
      o.push_back(pii(a[0],a[i]));
      a[0]-=a[i];
    }
  }
  o.push_back(pii(a[n-1],a[0]));
  cout << o[n-2].first-o[n-2].second << endl;
  rep(i,o.size()){
    cout << o[i].first << " " << o[i].second << endl;
  }
}