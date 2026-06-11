#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

void bubble(int p[], int n) {
  for(int i = 0; i < n; i++) {
    for(int j = n-1; j >= i+1; j--)
      if(p[j] < p[j-1]) swap(p[j],p[j-1]);
  }
}

int main() {
  int n,k,p[1100];
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> p[i];

  bubble(p,n);
  int ans = 0;
  for(int i = 0; i < k; i++) {
    ans += p[i];
  }
  cout << ans << endl;
}