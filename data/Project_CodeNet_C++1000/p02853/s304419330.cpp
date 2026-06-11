#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
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

const int mx=100010;
const ll mod=1e9+7;


int main(){
  int x,y;
  cin >> x >> y;
  if(x==1&&y==1){
    cout << 1000000 << endl; return 0;
  }
  ll ans = 0;
  if(x==3) ans += 100000;
  if(x==2) ans += 200000;
  if(x==1) ans += 300000;
  if(y==3) ans += 100000;
  if(y==2) ans += 200000;
  if(y==1) ans += 300000;
  cout << ans << endl;
  return 0;
}