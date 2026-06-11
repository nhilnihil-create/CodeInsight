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
        long long int sum;
        cin>>sum;
        long long int p=1e9+7;
        
        long long int arr[2005]={0};
        for(int i=3;i<=sum;i++)
        {
            arr[i]=1;
        }
        
        for(int i=4;i<=sum;i++)
        {
            for(int j=3;j<=i;j++)
            {
                arr[i]+=arr[i-j]%p;
                arr[i]%=p;
            }
        }
            
            cout<<arr[sum]<<endl;
	   
	}
	   
	   
	return 0;
}