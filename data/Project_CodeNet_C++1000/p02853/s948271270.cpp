#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,ans=0;
	cin>>x>>y;
	if(x==1 && y==1) ans+=400000;
	if(x==1) ans+=300000;
	if(x==2) ans+=200000;
	if(x==3) ans+=100000;
	x=y;
	if(x==1) ans+=300000;
	if(x==2) ans+=200000;
	if(x==3) ans+=100000;
	cout<<ans;
	return 0;	
}