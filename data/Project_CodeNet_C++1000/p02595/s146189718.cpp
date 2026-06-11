#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;


int main() {
  int n;
  ll d;
  cin >> n >> d;
  
  ll a = 0,b = 0;
  
  int ans = 0;
  REP(i,n){
    cin >> a >> b;
    if(d*d >= a*a + b*b){
      ans++;
    }
  }
  
  cout << ans << endl;
  
}