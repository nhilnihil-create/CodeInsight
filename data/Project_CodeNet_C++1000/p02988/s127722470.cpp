#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int n,p[100],sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> p[i];
  
  for(int i = 1; i < n-1; i++) {
    if(p[i-1] < p[i] & p[i] < p[i+1]) sum++;
    else if(p[i+1] < p[i] & p[i] < p[i-1]) sum++;
  }
  cout << sum << endl;
}