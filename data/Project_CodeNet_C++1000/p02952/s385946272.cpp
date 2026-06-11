#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,r,s=0,c;
 	cin>>n;
 	for(i=1;i<=n;i++)
 	{
	 	c=0;
 	     r=i;
        while(r>0)
 		{
 				r=r/10;
 				c++;
	    }
		if(c%2!=0)
			s++;
	}
	cout<<s<<endl;
 }