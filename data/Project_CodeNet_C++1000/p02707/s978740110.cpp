#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int a[n+1];
  for(int i = 2; i < n+1; i++){
    cin >> a[i];
  }
  
  int x[n+1] = {0};
  for(int i = 2; i < n+1; i++){
    x[a[i]]++;
  }
  
  for(int i = 1; i < n+1; i++){
    cout << x[i] << endl;
  }
}