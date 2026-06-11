#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> getDivisors(int n) {
  vector<int> res;
  for (int i = 1; i <= sqrt(n); i++) { 
    if (n % i == 0) { 
      if (n / i == i) {
        res.push_back(i);
      } else {
        res.push_back(i);
        res.push_back(n/i);
      }
    } 
  }
  return res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1 ; i * j <= n; j++) {
            if (n - i * j > 0) ans++;
        }
    }
    cout << ans << "\n";
}