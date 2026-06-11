#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,m,f=0;
 	cin>>n;
 	if(n<10)
 		f=1;
 	else
 		
 			for(i=2;i<10;i++)
 			{
 				if(n%i==0&&n/i<10)
 					{
 						f=1;	
					 }
			 }
		 
		if(f==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
 }