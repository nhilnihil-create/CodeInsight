#include<bits/stdc++.h>
using namespace std ;
int main()
{
  int n , k , count = 0; 
  cin >> n >> k ;
  vector<int> v (n) ;
  for (int i = 0 ; i < n ; i++)
  {
      cin >> v[i] ;
  }
 // sort(v.begin() , v.end());
  for (int i = 0 ; i < n; i ++)
  {
      if (v[i]>= k)
      count++ ;
  }
      cout <<count ;
}
