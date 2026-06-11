#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  double a, w = 0;
  
  REP(i,n) { 
    cin >> a;
    w += 1/a;
  }
  
  cout << 1/w << endl;  
  
}