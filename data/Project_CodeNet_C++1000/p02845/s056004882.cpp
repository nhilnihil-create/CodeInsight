#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int q[100005];
long long ans=1;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int k=0;
		cin>>q[i];
        int j;
		if(q[i]==c) ++k,j=3;
		if(q[i]==b) ++k,j=2;
		if(q[i]==a) ++k,j=1;
		if(j==1) a++;
		if(j==2) b++;
		if(j==3) c++;
		ans*=k;
		ans%=1000000007; 
	}
	cout<<ans<<endl;
	return 0;
}