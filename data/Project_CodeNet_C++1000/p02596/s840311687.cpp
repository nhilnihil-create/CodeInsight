#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;


int main(void){
  ll k;
  cin >> k;

  ll t = 0;
  for (ll i = 0; i < k; i++){
    t = (10*t + 7) % k;
    if (t == 0){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  
  return 0;
}
