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

int main(){
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  string s; cin >> s;
  bool f=0;
  rep(i,n){
    if(a<i&&i+1<c&&s[i]=='#'&&s[i+1]=='#'){
      cout << "No" << endl;
      return 0;
    }
    if(b<i&&i+1<d&&s[i]=='#'&&s[i+1]=='#'){
      cout << "No" << endl;
      return 0;
    }
    if(i+2<n&&b-1<=i&&i<d&&s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
      f=1;
    }
  }
  if(c>d&&f==0){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}