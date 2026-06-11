#include <bits/stdc++.h>
using namespace std;

bool p[300000];

void prime() {
  fill(p, p+300000, true);
  p[0] = false, p[1] = false;
  for(int i = 2; i < 300000; i++) {
    if(p[i]) {
      for(int j = 2; i*j < 300000; j++) {
	p[i*j] = false;
      }
    }
  }
}

int main() {
  int n;
  prime();

  while(cin >> n, n) {
    int ans = 0;
    for(int i = n+1; i <= 2*n; i++) {
      if(p[i]) ans++;
    }
    cout << ans << endl;
  }
}