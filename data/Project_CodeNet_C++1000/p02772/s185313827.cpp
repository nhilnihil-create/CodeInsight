#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  bool ans = true;
  
  int a;
  REP(i,n) {
    cin >> a;
    if (a % 2 == 0 && a % 3 != 0 && a % 5 != 0) ans = false;
  }
  
  cout << (ans ? "APPROVED" : "DENIED") << endl;

}