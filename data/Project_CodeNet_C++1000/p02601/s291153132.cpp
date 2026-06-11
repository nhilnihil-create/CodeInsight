#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,k,i=0;
	cin>>a>>b>>c>>k;
	
	
	while(a>=b&&i<=k)
	{
		i++;
		b*=2;
	}
	while(b>=c&&i<=k)
	{
		i++;
		c*=2;
	}
	if(a<b<c&&i<=k)
	{
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0;
}