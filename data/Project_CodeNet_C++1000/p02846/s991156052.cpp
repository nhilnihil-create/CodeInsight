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
  ll ta, tb; ll aa, ab; ll ba, bb;
  cin >> ta >> tb >> aa >> ab >> ba >> bb;
  if(ta*aa+tb*ab==ta*ba+tb*bb) cout << "infinity" << endl;
  else{
    if(aa<ba){
      swap(aa, ba); swap(ab, bb);
    }
    if(ta*aa+tb*ab-ta*ba-tb*bb>0){
      cout << 0 << endl; return 0;
    }
    ll tmp=ta*(aa-ba)/(ta*ba+tb*bb-ta*aa-tb*ab);
    if((ta*(aa-ba))%(ta*ba+tb*bb-ta*aa-tb*ab)==0){
      cout << 2*tmp << endl;
    }
    else{
      cout << tmp*2+1 << endl;
    }
  }
}