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
  
  int count = 0;
  rep(i,n) {
   if(a.at(i) % 2 == 0) {
    count++;
   }
  }
  
  int check = 0;
  rep(i,n) {
   if(a.at(i) % 2 == 0 ) {
     if(a.at(i) % 3 == 0 || a.at(i) % 5 == 0) {
     check++;
    }
   }
  }
  
  if (count == check) {
  cout << "APPROVED";
  }
  else {
   cout << "DENIED";
  }
  
}