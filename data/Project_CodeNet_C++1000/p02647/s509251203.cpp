#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  for(int i = 0; i < k; i++){
    vector<int> sum(n);
    for(int j = 0; j < n; j++){
      int l = max(0, j-a.at(j)), r = min(n, j+a.at(j) + 1);
      if(r < n) sum.at(r)--;
      sum.at(l)++;
    }
    int now = 0;
    for(int j = 0; j < n; j++){
      now += sum.at(j);
      a.at(j) = now;
    }
    if(a.at(0) == n && a.at(n-1) == n) break;
  }
  
  for(auto now : a) cout << now << " ";
  cout << endl;
}