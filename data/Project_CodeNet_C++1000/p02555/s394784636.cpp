#include<bits/stdc++.h>

using namespace std;

const long long mod=1e9+7;

long long a[2005];

void sq()
{
    a[0]=a[1]=a[2]=1;
    for(int i=3;i<=2000;i++) 
		a[i]=(a[i-3]+a[i-1])%mod;
}
int main()
{
	int n;
	cin>>n;
    sq();
    if(n<3) 
		cout<<0<<endl;
    else 
		cout<<a[n-3]<<endl;
    return 0;
}