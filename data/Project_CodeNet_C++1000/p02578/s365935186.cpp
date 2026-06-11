#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  long n,a[300000];
  cin >> n;  
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  long sum = 0;
  for(int i = 1; i < n; i++) {
    if(a[i] < a[i-1]) {
      sum+= a[i-1] - a[i];
      a[i] = a[i-1];
    }
  }

  cout << sum << endl;
  return 0;
}