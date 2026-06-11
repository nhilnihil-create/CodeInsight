#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln =  '\n';

const int mx=100010;
const ll mod=1e9+7;


int main(){
  string h,w;
  cin >> h >> w;
  int n=h.size();
  int ans = 0;
  rep(i,n){
    if(h[i]==w[i])ans++;
  }
  cout << ans << ln;
  return 0;
}