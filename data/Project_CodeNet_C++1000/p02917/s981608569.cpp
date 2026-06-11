#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int b[n];
  for(int i = 0;i < n-1;i++) cin >> b[i];
  int a[n+1] = {0};
  a[0] = b[0];
  a[n-1] = b[n-2];
  int sum = a[0] + a[n-1];
  for(int i = 1;i < n-1;i++){
    a[i] = min(b[i-1],b[i]);
    sum += a[i];
  }
  cout << sum << endl;
  
}