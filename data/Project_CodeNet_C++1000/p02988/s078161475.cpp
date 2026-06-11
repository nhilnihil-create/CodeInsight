#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int cnt = 0;
  for(int i = 1; i < n-1; i++) {
    if(p[i-1] < p[i] && p[i] < p[i+1]) cnt++;
    else if(p[i+1] < p[i] && p[i] < p[i-1]) cnt++;
  }
  cout << cnt << endl;
}