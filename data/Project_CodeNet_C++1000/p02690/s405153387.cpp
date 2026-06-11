#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){

  int x;
  cin >> x;

  for(int a = 1; a < 1000; ++a){
    ll a5 = 1;   //a^5
    REP(i,5) a5 *= a;

    for(int b = -1000; b < 1000; ++b){
      ll b5 = 1;
      REP(i,5) b5 *= b;
      if(a5 - b5 == x){
        cout << a << " "<< b << endl;
        return 0;
      }
    }
  }
  return 0;

}