#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+10;
int n,flag;
int fac[maxn];
int a[maxn];
void init(int n)
{
	fac[0]=0;
	for (int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1];
		int tmp=i;
		while (!(tmp&1)) tmp/=2,fac[i]++;
	}
}
int C(int n,int m) {return (fac[n]-fac[m]-fac[n-m])==0;}
int main()
{
	cin>>n;getchar();
	for (int i=1;i<=n;i++)
	{
		char c=getchar();
		a[i]=c-48;
		if (a[i]==2) flag=1;
	}
	init(n);
	if (flag)
	{
		int tmp=0;
		for (int i=1;i<=n;i++)
			if (a[i]==2) tmp+=C(n-1,i-1);
		cout<<tmp%2<<endl;
		return 0;
	}
	int tmp=0;
	for (int i=1;i<=n;i++)
		if (a[i]==3) tmp+=C(n-1,i-1);
	cout<<tmp%2*2<<endl;
    return 0;
}
