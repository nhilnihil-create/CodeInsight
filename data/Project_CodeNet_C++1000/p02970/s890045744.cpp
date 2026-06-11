#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,i,d,c=0;
 	cin>>n>>d;
 	if(n%(2*d+1)==0)
 		c=n/(2*d+1);
 	else
 		c=n/(2*d+1)+1;
 	cout<<c<<endl;
 }