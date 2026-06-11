#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;

int main() {
 int n;
 cin >> n;
 
 string s;
 cin >> s;
 
 for(int i = 0; i < s.size() -1; i++) {
  if(s.at(i) == s.at(i + 1)){
   n--;
   }
   }
   cout << n;
}