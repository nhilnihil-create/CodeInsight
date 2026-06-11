#include<iostream>
#include<string>
#include<cstring>
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
#define PI 3.141592653589793

int main(){
  int m, d; cin >> m >> d; int cnt = 0;
  rep(i, d+1){
    if(i<=11) continue;
    int k = i;
    int da = k%10; k/=10; int di = k%10;
    if(da*di>=2 && da*di<=m &&  da>1 && di>1) {cnt++; }
  }
  cout << cnt << endl;
}