#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	int q;
	cin >> q;
	atcoder::dsu d(n);
	while(q--)
	{
		int t,u,v;
		cin >> t >> u >> v;
		if(t)
		{
			cout<<d.same(u,v)<<endl;
		}
		else
		{
			d.merge(u,v);
		}
	}
}
