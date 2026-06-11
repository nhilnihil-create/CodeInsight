#include<bits/stdc++.h>
 
using namespace std;
 
long long arr[10000007] ;
 
int main()
{
    long long n , sum = 0 , i , j  ;
    cin>>n;
    for ( i=1 ; i<=n ; i++)
    {
                 for ( j = i ; j<=n ; j+= i )
                 {
                              arr[j]++;
                 }
    }

    for (i=1 ; i<=n ; i++)
    {
                 sum += (arr[i])*i ;
    }
   cout<<sum;
    return 0;
}