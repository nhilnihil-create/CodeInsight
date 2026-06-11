#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a;
	cin>>n>>a;
	int l=a;
	int r=n+l-1;
	int ans;
	if(r<=0)ans=r;
	else if(l>=0)ans=l;
	else ans=0;

	int answ = (r+l)*(r-l+1)/2-ans;
	cout<<answ;
}