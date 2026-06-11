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
const ll mod=998244353;
#define pai 3.141592653589793238462643383279


  


int main(){
  int h, w, m; cin >> h >> w >> m; set<pair<int, int>>st;
   int tate[h]={}, yoko[w]={};
  rep(i, m){
    int x, y; cin >> x >> y; x--; y--;
    st.insert({x, y}); tate[x]++; yoko[y]++;
  }
  int matate=0, mayoko=0;
  rep(i, h){
    if(tate[i]>matate) matate=tate[i];
  }
  rep(i, w){
    if(yoko[i]>mayoko) mayoko=yoko[i];
  }
  vector<int> chta, chyo;
  rep(i, h){
    if(tate[i]==matate) chta.push_back(i);
  }
  rep(i, w){
    if(yoko[i]==mayoko) chyo.push_back(i);
  }
  bool can = false;
  for(auto i: chta){
    for(auto j: chyo){
      if(st.count({i, j})) continue;
      else{
        can = true; break;
      }
    }
  }
  if(can) cout << matate+mayoko << endl;
  else cout << matate+mayoko-1 << endl;
}
    