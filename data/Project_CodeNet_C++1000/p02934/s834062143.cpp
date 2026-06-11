#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  long double sum = 0.0;
  for(int i = 0; i < n; i++){
    sum += (long double)(1.0 / a[i]);
  }
  
  sum =  (long double)(1.0 / sum);
  
  cout << fixed;
  cout << setprecision(20);
  cout << sum << endl;
}