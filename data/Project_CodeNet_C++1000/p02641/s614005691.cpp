#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll x, n;
  cin >> x >> n;
  
  set<ll> s;
  for (int i = 0; i < n; i++){
    ll p;
    cin >> p;
    
    s.insert(p);
  }
  int ans = -100, m = abs(x+100);
  for (int i = -100; i < 201; i++){
    if (abs(x-i) < m && s.find(i) == s.end()){
      ans = i;
      m = abs(x-i);
    }
  }
  cout << ans << endl;
  

  return 0;
}
