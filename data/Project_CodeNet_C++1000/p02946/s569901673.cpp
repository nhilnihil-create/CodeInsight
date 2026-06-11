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

const long INF = 1e9 + 1;

int main() {
  int k,x;
  cin >> k >> x;
  for(int i = x-k+1; i < x+k; i++) {
    if(i == x+k-1) cout << i << endl;
    else cout << i << " ";
  }
}