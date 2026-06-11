#include<bits/stdc++.h>
using namespace std;

long long int n,a[200010],r[2025],ans,i,p[200010];
string s;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;n=s.size();
	p[n]=1;for (i=n-1;i>0;i--) p[i]=(p[i+1]*10)%2019;
	a[n+1]=0;
	for (i=n;i>0;i--) a[i]=(a[i+1]+p[i]*(s[i-1]-'0'))%2019;
	for (i=0;i<2019;i++) r[i]=0;
	for (i=1;i<n+2;i++) r[a[i]]++;
	ans=0;
	for (i=0;i<2019;i++) ans=ans+(r[i]*(r[i]-1))/2;
	cout<<ans;
}
