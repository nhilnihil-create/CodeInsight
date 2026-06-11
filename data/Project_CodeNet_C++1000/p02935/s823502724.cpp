#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;

 int main() {
  int n;
  cin >> n;
  
  vector<double> a(n);
  rep(i,n) {
   cin >> a.at(i);
   }
   
   sort(a.begin(),a.end());
   for(int i = 0; i < n - 1;i++) {
    double div = 0;
    div = (a.at(0) + a.at(1)) / 2;
    a.erase(a.begin() + 1);
    a.erase(a.begin());
    a.push_back(div);
    sort(a.begin(),a.end());
    }
   
   cout << a.at(0);
 }