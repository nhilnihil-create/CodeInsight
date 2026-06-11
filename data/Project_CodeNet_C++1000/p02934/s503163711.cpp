#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0; long double ans = 0;
  cin >> N;
  vector<long double>A(N);
  rep(i,N){
    cin >> A[i];
    ans += 1/A[i];
  }
  cout << fixed << setprecision(10);
  cout << 1/ans;
}

  