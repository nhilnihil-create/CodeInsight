#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int r=0,g=0,b=0;
  rep(i,n){
    if(s[i]=='R')r++;
    if(s[i]=='G')g++;
    if(s[i]=='B')b++;
  }
  ll ans = r*g*b;
  rep(j,n)rep(i,j){
    if(s[i]!=s[j]){
      int k = 2*j-i;
      if(k>=n)continue;
      if(s[i]!=s[k]&&s[j]!=s[k])ans--;
    }
  }
  cout << ans << endl;
}