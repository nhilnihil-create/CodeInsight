#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n,q;
	cin >> n >> q;

	atcoder::fenwick_tree<ll> tw(n);

	for(int i = 0;i<n;i++)
	{
		int a;
		cin >> a;
		tw.add(i,a);
	}
	while(q--)
	{
		int t,a,b;
		cin >> t >> a >> b;
		if(t)
		{
			cout<<tw.sum(a,b)<<endl;
		}
		else
		{
			tw.add(a,b);
		}
	}
}
