#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


int main(){
	long long  h,ans,c;
	ans=1;
	c=1;
	cin>>h;
	while(h>1)
	{
		h=h/2;
		ans=ans*2;
		c=c+ans;		
	}
	cout<<c;
return 0 ;
}
