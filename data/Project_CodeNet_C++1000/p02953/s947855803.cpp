#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

int main() {
  int n,h[110000], ma[110000];
  cin >> n;
  
  for(int i = 0; i < n; i++) {
    cin >> h[i];
    ma[0] = h[0];
    if(i > 0) ma[i] = max(ma[i-1], h[i]);
    
    if(h[i] < ma[i] - 1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
