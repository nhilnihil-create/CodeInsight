#include <bits/stdc++.h>
using namespace std;
int main()
 {
 	int k,a,b,i,f=0;
 	cin>>k>>a>>b;
 	for(i=a;i<=b;i++)
 		{
 			if(i%k==0)
 			{
			 cout<<"OK"<<endl;
			 break;
 			}
 			else 
 				f++;
		 }
	if(f==(b-a+1))
		cout<<"NG"<<endl;
 	return 0;
}
 	
 					