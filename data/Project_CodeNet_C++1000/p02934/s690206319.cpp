#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n){cin >> x[i];}
  
  long double bunshi = 1.000000;
  long double bunbo = 0.000000;
  rep(i,n){
    bunbo += 1.000000/x[i];
  }
  
  long double ans = bunshi/bunbo;
  cout << ans << endl;
}