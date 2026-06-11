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
  int n;
  cin >> n;
  pair<int, int> a[110000];
  for(int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i+1;
  }
  sort(a,a+n);

  for(int i = 0; i < n; i++) {
    if(i != n-1) cout << a[i].second << " ";
    else cout << a[i].second;
  }
  cout << endl;
}