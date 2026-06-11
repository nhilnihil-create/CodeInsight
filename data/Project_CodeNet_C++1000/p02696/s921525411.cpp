#include<bits/stdc++.h>
#define int long long int
using namespace std;
 
int32_t main()
{
    int m,s,t;
    cin>>m>>s>>t;
    if(t>=s)
    {
      	t=s-1;
    	cout<<floor((m*t)/s);
    }
    else
    {
        int x=t;
        cout<<floor((m*x)/s)-m*floor(x/s);
        
    }
 
    
 
}