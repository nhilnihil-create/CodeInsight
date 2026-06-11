#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int mod = 1e9+7;
long long a[2001]={0,0,0,1,1,1,2,3,4,6,9,13};
int main()
{
	int x;
	cin>>x;
	for(int i=12;i<=x;i++)
		a[i]=(a[i-1]%mod+a[i-3]%mod)%mod;
	cout<<a[x]<<endl;	
	return 0;
}
