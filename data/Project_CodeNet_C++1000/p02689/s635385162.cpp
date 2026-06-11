#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> h(n+1);//index=展望台i,value=標高
  set<int> s;
  for(int i = 1; i <= n; i++) {
    cin >> h[i];
    s.insert(i);
  }
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if(h[a] == h[b]) {
      s.erase(a);
      s.erase(b);
    }
    else if(h[a] > h[b]) s.erase(b);
    else s.erase(a);
  }
  cout << s.size();
}