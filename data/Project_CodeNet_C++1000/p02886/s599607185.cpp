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
  int n,d[100];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> d[i];
  
  int sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++)
      sum += d[i]*d[j];
  }

  cout << sum << endl;  
}