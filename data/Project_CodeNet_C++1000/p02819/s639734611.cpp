#include <iostream>
#include<bits/stdc++.h>

using namespace std;
bool isPrime (int x ) ;

int main()
{
    int x ;
    scanf ("%d",&x);
    while (1)
    {
                 if (isPrime(x))
                 {
                            printf ("%d",x);  break ;
                 }
                 x++;
    }
    return 0;
}
bool isPrime (int x )
{
             if (x==1) return false ;
             int i ;
             for (i=2 ; i<x ; i++)
             {
                          if (x%i==0)
                                       return false ;
             }
             return true ;
}
