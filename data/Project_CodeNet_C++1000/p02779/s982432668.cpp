#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n;
  cin >> n;
  
  int64_t a[n];
  for(int64_t i = 0; i < n; i++){
    cin >> a[i];
  }
  
  sort(a,a+n);
  for(int64_t i = 0; i < n-1; i++){
    if(a[i] == a[i+1]){
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
}