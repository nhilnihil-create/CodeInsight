#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	 long long int n,s=0;
 	cin>>n;
 	while(n>0)
 	{
 		if((n%3!=0)&&(n%5!=0))
 			s=s+n;
 		n--;
	 }
		cout<<s<<endl;		
 	return 0;
 }