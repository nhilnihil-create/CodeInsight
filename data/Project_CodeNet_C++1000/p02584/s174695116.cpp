#include<bits/stdc++.h>
using namespace std;

int  main()
{

    long long x,k ,d ,ans = 0; 

    cin>>x>>k>>d; 
    if(x< 0 )
    {
        x *=-1 ; 

    }
    double q= (double) x/d; 



    if(q > k)
    {
        ans = x - k*d; 
    } 
    else 
    {
        
        k  -= x/d ;
    
        
        
         

        if(k%2 ==0 )
        {
            ans = x%d; 
        } 
        else
        {
            ans = abs( d - x%d) ; 
        }
        

        
    }

    cout<<ans; 


    





}