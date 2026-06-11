#include<bits/stdc++.h>
#define MAX 5000
#define MOD 1000000007
using namespace std;
vector<int> p,c;
long long go(int start, int k)
{
	long long sum = 0;
	int ii = start;
	int steps = 0;
	vector<int> v;
	do
	{
		ii = p[ii];
		v.push_back(c[ii]);
		sum += 1LL*c[ii];
		++steps;
	}
	while(ii^start);
	long long tmp = 0, res = LLONG_MIN;
	for(int i=0;i+1<=k&&i<v.size();++i)
	{
		tmp += 1LL*v[i];
		if(sum>0)
			res = max(res,tmp+(k-i-1)/steps*1LL*sum);
		else res = max(res,tmp);
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	p = vector<int>(n+1), c = vector<int>(n+1);
	for(int i=1;i<=n;++i)
		cin>>p[i];
	for(int i=1;i<=n;++i)
		cin>>c[i];
	long long ans = LLONG_MIN;
	for(int i=1;i<=n;++i)
		ans = max(ans,go(i,k));
	cout<<ans<<endl;
	return 0;
}