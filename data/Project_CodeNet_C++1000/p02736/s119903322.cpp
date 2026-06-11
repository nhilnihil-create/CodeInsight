#include<bits/stdc++.h>
using namespace std;
int main(){
	int b[3]={},n,f=0;
	string a;
	cin>>n>>a;
	for(int i=0;i<n;i++) 
	{
		--a[i];
		if(a[i]=='1') f=1;
		b[a[i]-'0']+=(((n-1)&i)==i);
	}
	if(b[1]&1) cout<<"1";
	else if(!f&&(b[2]&1)) cout<<"2";
	else cout<<"0";
	return 0;
}
