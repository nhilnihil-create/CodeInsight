#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll x, y;
  cin >> x >> y;
  
  if (y % 2 == 1)
    cout << "No" << endl;
  else {
    if (y - 2*x >= 0 && 2*x - y/2 >= 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
