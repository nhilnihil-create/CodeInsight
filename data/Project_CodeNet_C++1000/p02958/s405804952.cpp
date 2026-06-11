#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int n;
 cin >> n;
 
 vector<int> a(n);
 rep(i,n) {
  cin >> a.at(i);
  }
  
  vector<int> b(n);
  rep(i,n) {
  b.at(i) = a.at(i);
  }
  
  
  sort(a.begin(),a.end());
  
  int count = 0;
  rep(i,n) {
  if(a.at(i) != b.at(i)) {
  count++;
  }
  }
  
  if(count == 0 || count == 2){
  cout << "YES";
  }
  else {
  cout << "NO";
  }
  
  
 }