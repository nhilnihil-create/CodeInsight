#include <bits/stdc++.h>
using namespace std;
int main(void)
{
          int n, i , c = 0 ;
          scanf("%d", &n) ;
          int a[n] ,b[n];
          for(i = 0 ; i < n ; i++)
          {
                    scanf("%d", &a[i]) ;
                    b[i] = a[i] ;
          }
          sort(b, b+n) ;
          for(i = 0 ; i < n ; i++)
          {
                    if(a[i] != b[i]) c++ ;
                    if(c >2) break ;
          }
          if(c == 2 || c == 0) printf("YES\n") ;
          else printf("NO\n") ;
}