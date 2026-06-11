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
  int N; cin >> N; map<ll, int>mp; bool zero = true;
  rep(i, N){
    ll a; cin >> a; mp[a]++; if(a!=0) zero = false;
  }
  if(zero){
    cout << "Yes" << endl; return 0;
  }
  if(mp.size()==2){
    for(auto t: mp){
      if(t.first!=0){
        if(t.second==2*mp[0]){
          cout << "Yes" << endl; return 0;
        }
      }
    }
  }
  int cnt = 0; ll tmp[3];
   if(N%3 || mp.size()!=3){
    cout << "No" << endl;  return 0;
  }
  for(auto t: mp){
    if(t.second!=N/3){
      cout << "No" << endl; return 0;
    }
    tmp[cnt] = t.first;
    cnt++;
  }
  if((tmp[0]^tmp[1])!=tmp[2]){
    cout << "No" << endl; return 0;
  }
  cout << "Yes" << endl;
}
