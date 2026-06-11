#include <bits/stdc++.h>
using namespace std ;

int main()
{ 
  int m, d, a, b ;
  cin >> m >> d ;
  a = d / 10 ;
  b = d % 10 ;

  int count = 0 ;
  for(int k = 1 ; k <= m ; k++)
  { 
    for(int i = 2 ; i <= a ; i++)
    {
      for(int j = 2 ; j <= 9 ; j++)
      {
        //cout << k << " " << i << " " << j << endl ;
        if(i * 10 + j > d)
        {
          continue ;
        }
        //cout << k << " " << i << " " << j << endl ;
        if(i * j == k)
        {
          //cout << k << " " << i << " " << j << endl ;
          count++ ;
        }
      }
    } 
  }

  cout << count << endl ;
}
