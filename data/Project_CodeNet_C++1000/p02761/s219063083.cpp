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

const long INF = (1<<30);

int main() {
  int n,m,s[10],c[10];
  cin >> n >> m;
  for(int i = 0; i < m; i++)
    cin >> s[i] >> c[i];
  
  int st = pow(10, n-1);
  if(st == 1) st = 0;
  int end = pow(10, n);
  
  
  for(int i = st; i < end; i++) {
    bool flag = 1;
    string str = to_string(i);
    for(int j = 0; j < m; j++) {
      if(str[s[j]-1] != c[j]+'0') 
        flag = 0; 
    }
    if(flag) {
      cout << str << endl;
      return 0;
    }
  }
  cout << -1 << endl; 
}