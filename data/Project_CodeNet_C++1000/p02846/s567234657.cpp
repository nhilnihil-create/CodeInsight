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
  ll s,t;
  cin >> s >> t;
  pair<ll,ll> a,b;
  cin >> a.F >> a.S >> b.F >> b.S;
  if(a.F<b.F) swap(a,b);
  if(a.F*s+a.S*t == b.F*s+b.S*t){ cout << "infinity" << endl; return 0; }
  ll A = a.F*s+a.S*t;
  ll B = b.F*s+b.S*t;
  if(A > B){ cout << 0 << endl; return 0; }
  ll dis = b.F*s+b.S*t - (a.F*s+a.S*t);
  ll mome = (a.F-b.F)*s;
  cout << (mome/dis)*2+(mome%dis!=0?1:0) << endl;

  return 0;  
}