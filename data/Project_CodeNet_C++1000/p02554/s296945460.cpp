#include <iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p)  
{  
    long long int res = 1;      
  
    x = x % p; 
   
    if (x == 0) return 0; 
  
    while (y > 0)  
    {  
        
        if (y & 1)  
            res = (res*x) % p;  
  
          
        y = y>>1;  
        x = (x*x) % p;  
    }  
    return res;  
}  
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t=1;
	while(t--)
	{
        long long int p=1e9+7;
        long long int n;
        cin>>n;
        
        long long int ans1=power(10,n,p);
        long long int ans2=2*power(9,n,p);
        long long int ans3=power(8,n,p);
        long long int res=(((ans1-ans2)%p + p )%p +ans3)%p;
        
       // long long int res= (ans1-ans2)%p;
        res=(res+p)%p;
        
        cout<<res<<endl;
            
            
	   
	}
	   
	   
	return 0;
}