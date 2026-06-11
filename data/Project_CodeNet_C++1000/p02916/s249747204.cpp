#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, b = -1, S = 0;
  cin >> n;
  set<int> s;
  for(int i = 0;i < n;i++) {
    int a;
    cin >> a;
    if(a == b + 1) s.insert(b);
    b = a;
  }
  for(int i = 0;i < n;i++) {
    int B;
    cin >> B;
    S += B;
  }
  for(int i = 1;i < n;i++) {
    int c;
    cin >> c;
    if(s.count(i)) S += c;
  }
  cout << S << endl;
}