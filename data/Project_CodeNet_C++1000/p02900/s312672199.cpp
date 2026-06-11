#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll m,n,cnt,sum;
int Prime[200005],yy[2000005]; 
inline void getprime()
{
	for(int i=1;i<=2e6;++i) yy[i]=1;
	for(int i=2;i<=2e6;++i)
	{
		if(yy[i]) Prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*Prime[j]<=2e6;++j)
		{
			yy[i*Prime[j]]=0;
			if(i%Prime[j]==0) break;
		}
	}
}
int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    cin>>m>>n;
    ll k=__gcd(m,n);
    getprime();
    for(int i=1;i<=cnt&&Prime[i]<=k;++i)
    {
    	if(k%Prime[i]==0) sum++;
    	while(k%Prime[i]==0) k/=Prime[i];
	}
	if(k>1) sum++;
	cout<<sum+1;
	return 0;
}