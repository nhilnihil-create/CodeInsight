#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
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
   b.at(a.at(i) - 1) = i + 1;
   } 
 
 rep(i,n) {
  cout << b.at(i) << ' ';}
 
 }