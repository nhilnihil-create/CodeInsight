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
        
 int count = 0;
 for(int i = 0; i < n - 2; i++) {
  if( (a.at(i) < a.at(i + 1) && a.at(i + 1) < a.at(i + 2)) || (a.at(i) > a.at(i + 1) && a.at(i + 1) > a.at(i + 2))  ) {
   count++;}
 }
        
        cout << count;
}