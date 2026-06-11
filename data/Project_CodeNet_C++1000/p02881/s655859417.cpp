#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int main()
{
	long long int i,n,p,x;
	
	cin>>n;
	long long int min=n-1;
	for(i=2;i<=sqrt(n);i++) 
    {  
        if(n%i==0)  
        {  
            p= n/i; 
			x=i+p-2;
			if(x<=min)
				min=x; 
        }  
    }  
    cout<<min<<endl;
}