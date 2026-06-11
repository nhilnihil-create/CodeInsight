#include<bits/stdc++.h>
using namespace std;

int main()
{    long long n,D,X,Y,c,e,count=0;
 
    cin>>n>>D;
    
    for(long long i=0;i<n;i++)
    {
        cin>>X>>Y;
    
        if(X * X + Y * Y <= D * D)
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}