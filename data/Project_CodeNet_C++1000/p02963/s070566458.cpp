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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  ll S; cin >> S;
  ll x2, x3, y2, y3;
  x2 = 1e9;
  y3 = (S-1)/(ll)pow(10, 9) + 1;
  x3 = 1;
  y2 = ((ll)pow(10,9) - S%(ll)pow(10, 9))%(ll)pow(10, 9);
  cout << 0 << " " << 0 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}
      