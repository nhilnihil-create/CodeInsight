#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  long n,a[300000], num[300000];
  cin >> n;
  for(int i = 0; i < 300000; i++)
    num[i] = 0;
  
  for(int i = 1; i < n; i++) {
    cin >> a[i];
    num[a[i]-1]++;
  }
  
  for(int i = 0; i < n; i++)
    cout << num[i] << endl;
  
  return 0;
}