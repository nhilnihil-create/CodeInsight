#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> pr;
  int sum = 0;
  rep(i,n) {
    int a;
    cin >> a;
    sum += a;
    pr.push(a);
  }
  rep(i,m) {
    if (pr.top() < (double)sum/(4*m)) {
      cout << "No" << endl;
      return 0;
    }
    pr.pop();
  }
  cout << "Yes" << endl;
  return 0;
}