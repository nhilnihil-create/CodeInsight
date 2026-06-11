#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
vi a;
const int N = 1e6+1;
int o[N];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<N;i++)	o[i] = 0;
	int ans = 0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		a.push_back(j);	
	}
	sort(a.begin(),a.end());
	for(i=0;i<n;i++)
	{
		if(o[a[i]]<=1)
		{
			for(j=a[i];j<N;j+=a[i])
			{
				o[j]++;
			}
		}
	}
	for(i=0;i<n;i++)	if(o[a[i]]==1)		ans++;
	printf("%d",ans);
}
