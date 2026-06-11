#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n , a[101] = {0} ;
    cin >> n ;
    int x = 0 ;
    for(int i = 1 ; i <= n ; i++)
    {
         cin >> a[i] ;
         if(i%2)
         {
              if(a[i]%2)
              {
                   x++ ;
              }
         }
    }
    cout << x << endl ;
}
