#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y, A, B, C;
  cin >> x >> y >> A >> B >> C;
  vector<int> Red(A), Green(B), Non(C);
  for (int &e : Red) cin >> e;
  for (int &e : Green) cin >> e;
  for (int &e : Non) cin >> e;
  sort(Red.begin(),Red.end(),greater<int>());
  sort(Green.begin(),Green.end(),greater<int>());
  sort(Non.begin(),Non.end(),greater<int>());
  long long ans = 0;
  priority_queue<int,vector<int>,greater<int>> eat;
  for (int i = 0; i < x; i++) {
    ans += Red[i];
    eat.push(Red[i]);
  }
  for (int i = 0; i < y; i++) {
    ans += Green[i];
    eat.push(Green[i]);
  }
  for (int i = 0 ; i < C; i++) {
    if (eat.top() > Non[i]) break;
    ans += Non[i]-eat.top();
    eat.pop();
    eat.push(Non[i]);
  }
  cout << ans << endl;
}