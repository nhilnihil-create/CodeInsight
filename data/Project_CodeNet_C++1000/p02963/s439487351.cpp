#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long S;cin>>S;
	if(S==1000000000000000000ll)
	{
		puts("0 0 1000000000 0 0 1000000000");
		return 0;
	}
	cout<<"0 0 ";
	int t=1000000000,v=S/t;
	int vvv=S%t;
	cout<<t<<' '<<1<<' ';
	cout<<(t-vvv)<<' '<<(v+1)<<endl;
}