#include <bits/stdc++.h>

using namespace std;

#define ll long long

int a, b;

void solve() {
  cin >> a >> b;
  if (((a>=1)&&(a<=9))&&((b>=1)&&(b<=9))) {
    cout << a*b << '\n';
  } else {
    cout << "-1\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
} 
