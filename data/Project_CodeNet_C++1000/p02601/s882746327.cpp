#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,g,b;
	int k;
	cin>>r>>g>>b>>k;
	while(g<=r){
		k--;
		g*=2;
	}
	while(b<=g){
		k--;
		b*=2;
	}
	if(k>=0)
	 cout<<"Yes";
	else
	 cout<<"No";
	return 0;
}