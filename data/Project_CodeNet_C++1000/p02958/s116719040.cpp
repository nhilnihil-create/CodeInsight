#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,p[100],q[100];
  cin >> n;
  
  for(int i = 0; i < n; i++) 
    cin >> p[i];
  
  for(int i = 0; i < n; i++)
    q[i] = p[i];

  sort(p,p+n);
  int num = 0;
  for(int i = 0; i < n; i++) {
    p[i] -= q[i];
    if(p[i] < 0) num++;
  }
  if(num > 1)
    cout << "NO" << endl;
  else cout << "YES" << endl;
  
}