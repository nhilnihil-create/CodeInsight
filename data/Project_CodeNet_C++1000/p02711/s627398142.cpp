#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,r,f=0;
 	cin>>n;
 	while(n!=0)
 	{
 		r=n%10;
 		n=n/10;
 		if(r==7)
 			f++;	
	 }
	 if(f==0)
	 	cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
 	return 0;
}
 	
 					