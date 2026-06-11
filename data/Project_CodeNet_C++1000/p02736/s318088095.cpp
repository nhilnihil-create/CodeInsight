//love yjl forever
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int INF=0x3f3f3f3f,N=1e6+5;
int n;
int two[N];
int calc(int x)
{
	int s=0;
	while(x%2==0)
	{
		x=x/2;
		s++;
	}
	return s;
}
int a[N];
int main()
{
/*	freopen("","r",stdin);
	freopen("","w",stdout);*/
	int i;

	string s;
	cin>>n;
	for(i=1;i<=n;i++)
		two[i]=two[i-1]+calc(i);

//	for(i=1;i<=n;i++)
//		cout<<two[i]<<" ";
//	cout<<endl;
	cin>>s;
	for(i=1;i<=n;i++)
		a[i]=s[i-1]-'1';
		
	bool f=0;
	for(i=1;i<=n;i++)
		if(a[i]==1) f=1;
	if(!f)
	{
		for(i=1;i<=n;i++)
			a[i]=a[i]/2;
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
	//	cout<<two[n]-two[i]-two[n-i]<<" "<<a[i]<<endl;
		if((two[n-1]-two[i-1]-two[n-i])<=0)
		{
			ans+=a[i];
			ans=ans%2;
		}
	}
	if(!f) ans=ans*2;
	cout<<ans<<endl;
}