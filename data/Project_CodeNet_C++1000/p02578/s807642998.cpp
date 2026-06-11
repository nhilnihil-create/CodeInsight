#include<bits/stdc++.h>
using namespace std; 

int main()
{
    int n; 
    cin>>n; 


    long long a[n],max_1[n],sum =0 ;

    for(int i=0 ; i< n;i++ )
    {
        cin>>a[i];
        if(i==0 )
        {
            max_1[i] = a[i];
        }
        else if( a[i]  > max_1[i -1])
        {
            max_1[i] = a[i];
        }
        else 
        max_1[i] = max_1[i-1];
    }

    for(int i=0 ; i<n;i++ )
    {
        if(a[i] <  max_1[i])
        {
            sum += max_1[i] - a[i];

        }
    }
    cout<<sum; 

}