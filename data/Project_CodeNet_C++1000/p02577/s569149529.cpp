#include<bits/stdc++.h>
using namespace std;
int main()
{
	string n;
	long long i,l,j,k,s=0;
	cin>>n;
	l=n.length();
	for(i=0;i<l;i++){
		s+=(n[i]-48);
	}
//	cout<<s<<endl;
	if(s%9==0)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
