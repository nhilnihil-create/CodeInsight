#include <bits/stdc++.h>
using namespace std;

int main() {
  double n, a, b;
  cin >> n;
  priority_queue<double, vector<double>, greater<double>> v;
  for(int i = 0;i < n;i++) {
    cin >> a;
    v.push(a);
  }
  while(v.size() > 1) {
    b = v.top();
    v.pop();
    b += v.top();
    v.pop();
    v.push(b / 2);
  }
  cout << v.top() << endl;
}