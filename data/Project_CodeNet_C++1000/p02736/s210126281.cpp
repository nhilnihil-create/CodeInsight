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
  int n; cin >> n; string S; cin >> S; bool one = false;
  rep(i, n){
    if(S[i]=='3') S[i]='2';
    else if(S[i]=='2') S[i]='1';
    else S[i]='0';
  }
  rep(i, n){
    if(S[i]=='1') one=true;
  }
  int ans = 0;
  if(!one){
    rep(i, n){
      if(S[i]=='2') S[i]='1';
    }
  }
  rep(i, n){
    if(n-1 == (i|(n-1-i)) && S[i]=='1') ans++;
  }
  ans%=2;
  if(!one) ans*=2;
  cout << ans << endl;
}