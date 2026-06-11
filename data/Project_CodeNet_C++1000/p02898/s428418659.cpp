#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h.at(i);
  sort(h.begin(),h.end());
  reverse(h.begin(),h.end());
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(h.at(i) >= k){
      cnt++;
    } else {
      break;
    }
  }
  cout << cnt << endl;
}