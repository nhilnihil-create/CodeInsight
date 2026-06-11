#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  vector<int> w(n);
  int a = 0;
  REP(i,n) {
    cin >> w[i];
    a += w[i];
  }
  
  int b = 0;
  int c = 10000;
  REP(i,n) {
    a -= w[i];
    b += w[i];
    if (c > abs(a-b)) c = abs(a-b);
    else break;
  }
    
  cout << c << endl;
}