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
  int n,a[30],b[30],c[30];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    sum += b[i];
  }
  for(int i = 0; i < n-1; i++)
    cin >> c[i];
  
  for(int i = 0; i < n-1; i++) {
    if(a[i] + 1 == a[i+1]) sum += c[a[i]-1];
  }
  cout << sum << endl;  
}