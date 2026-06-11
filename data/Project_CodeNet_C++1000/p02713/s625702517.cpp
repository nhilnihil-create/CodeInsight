#include <bits/stdc++.h>
#define rep(i,n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  ll sum = 0;
  
  rep(i, N){
   rep(j, N){
    rep(k, N){
      sum += gcd(gcd(i,j),k);
    }
   }
  }
  
  cout << sum << endl;
  return 0;
}


