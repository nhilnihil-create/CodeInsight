#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n, k;
  cin >> n >> k;
  
  vector<int> h(n);
  int cnt = 0;
  REP(i,n) {
    cin >> h[i];
    if (h[i] >= k) cnt++;
  }
  
  cout << cnt << endl;
    
}