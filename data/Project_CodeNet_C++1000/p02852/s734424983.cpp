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
  int n,m;
  cin >> n >> m;
  string s; cin >> s;
  vector<int> ans(0);
  int i=n,j=n;
  while(i!=0){
    j=i-m;
    while(j<0||s[j]=='1'){
      j++;
    }
    if(i==j){
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(i-j);
    i=j;
  }
  int l=ans.size();
  for(int i=l-1;i>=0;i--){
    cout << ans[i] << " ";
  }cout << endl;
}