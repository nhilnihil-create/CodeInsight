#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
   

int main()
 {
 	long long int n,i,k,j,ans,s=0;
 	cin>>k;
 	for(i=1;i<=k;i++)
 		{
 			for(j=1;j<=k;j++)
 			{
 				for(n=1;n<=k;n++)
 					{
					 
 					ans=gcd(i,j);
 					s+=gcd(ans,n);
 				}
			 }
		 }
 	cout<<s<<endl;
 }
 	