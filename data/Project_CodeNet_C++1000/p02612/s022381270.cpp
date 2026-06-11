#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,ans; 

    cin>> n ;

    if(n%1000 ==0 )
    {
        ans =0 ; 
    }
    else 
    {
        ans = 1000 -n%1000;
    }

    cout<<ans ; 


}