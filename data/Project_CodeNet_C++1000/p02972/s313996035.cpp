#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  bool ok = true;
  vector<int> ans(n);
  for(int i = n-1; i >= 0; i--){
    int ne = (i+1) * 2 - 1;
    int now = a.at(i);
    while(ne < n){
      now ^= a.at(ne);
      ne += i + 1;
    }
    a.at(i) = now;
  }
  
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(a.at(i)) cnt++;
  }
  
  cout << cnt << endl;
  for(int i = 0; i < n; i++){
    if(a.at(i)) cout << i + 1 << " ";
  }
  cout << endl;
}