#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int a[n];
  rep(i,n) cin >> a[i];
  
  int max1 = 0, max2 = 0;
  rep(i,n)
  {
    if(a[i] > max1)
    {
      max1 = a[i];
    }else if(a[i] > max2 && a[i] <= max1){
      max2 = a[i];
    }
  }
  
  rep(i,n)
  {
    if(a[i] != max1)
    {
      cout << max1 << endl;
    }else{
      cout << max2 << endl;
    }
  }
      
}