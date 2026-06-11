#include<bits/stdc++.h>
using namespace std; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  string s;
  cin >> s;
  int sum = 0;
  for (auto c : s) 
    sum += c - '0';
  cout << (sum % 9 == 0 ? "Yes" : "No");
}