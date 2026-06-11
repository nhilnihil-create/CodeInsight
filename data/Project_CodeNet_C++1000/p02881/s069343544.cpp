#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;
  ll ans = 1000000000000000;

  double sqrtNum = sqrt(n);
  sqrtNum += 0.5;

  int i = 0;
  while(i <= sqrtNum){
    ll m = 0;
    if(i != 0){
      if(n % i == 0){
        m += i;
        m += n / i;
        ans = min(ans,m);
      }
    }
    i++;
  }
    

  cout << ans-2 << endl;
  
  
}