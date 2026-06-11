#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  vector<int> ans(n);
  for(int i = 1; i < n; i++){
    if(i % 2) sum -= a.at(i) * 2;
  }
  ans.at(0) = sum;
  for(int i = 1; i < n; i++){
    ans.at(i) = a.at(i-1) * 2 - ans.at(i-1);
  }
  
  for(int i = 0; i < n; i++) cout << ans.at(i) << " ";
  cout << endl;
}