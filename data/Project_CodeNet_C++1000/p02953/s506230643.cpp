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
  int n,h[110000];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> h[i];

  bool flag = 0;
  for(int i = 0; i < n-1; i++) {
    if(flag & h[i] == h[i+1] + 1) {
      cout << "No" << endl;
      return 0;
    }

    if(h[i] > h[i+1]) {
      if(h[i] == h[i+1] + 1) flag = 1;
      else {
        cout << "No" << endl;
        return 0;
      }
    }
    else if(h[i] < h[i+1]) flag = 0;
  }

  cout << "Yes" << endl;
}
