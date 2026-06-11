#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  string s, t;
  cin >> n >> s >> t;
  
  vector<char> u(2*n);
  REP(i,n) {
    u[2*i] = s[i];
    u[2*i+1] = t[i];
  }
  REP(i,2*n) {
    cout << u[i];
  }
    
}