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
  int n,k,q,num[110000];
  cin >> n >> k >> q;
  for(int i = 1; i <= n; i++)
    num[i] = 0;

  for(int i = 0; i < q; i++) {
    int a; cin >> a;
    num[a]++;
  }
  
  for(int i = 1; i <= n; i++) {
    if(num[i] > q-k) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}