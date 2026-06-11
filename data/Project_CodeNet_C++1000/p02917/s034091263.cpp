#include<bits/stdc++.h> 
using namespace std ; 
int main()
{


  int n ; cin >> n ; 
  int a[n] ; 
  for(int i = 0 ; i < n-1 ; i++)
  cin >> a[i] ; 
  
  int sum = a[0] ; 
  
  for(int i = 0 ; i < n-2 ; i++)
    {sum += min(a[i] , a[i+1]) ; }
  
  sum += a[n-2] ;
  cout << sum << endl ; 
  
}