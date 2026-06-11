#include<bits/stdc++.h>
using namespace std;

int  main()
{
    unsigned long long  n,x,t ; 
    cin>>n>>x>>t; 

    long long int ratio = n/x; 

    if(n%x !=0)
    {
     ratio += 1 ; 
    }

    cout<<t*(ratio);


}