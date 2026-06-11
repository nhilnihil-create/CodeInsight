#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20,MOD=2019;

int n;
char a[N];
long long v,ans;

int main()
{
	scanf(" %s",a+1);
	n=strlen(a+1);

	vector <int> prev(MOD,0);
	prev[0]++;
	for(int i=1;i<=n;i++)
	{
		vector <int> curr(MOD,0);
		for(int i=0;i<MOD;i++) curr[(i*10)%MOD]+=prev[i];
		prev=curr;


		v=(v*10+a[i]-'0')%MOD;
		prev[v]++;
		ans+=prev[v]-1;
	}

	printf("%lld",ans);
}