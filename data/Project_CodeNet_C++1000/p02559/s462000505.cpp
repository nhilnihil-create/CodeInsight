#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 500005;
ll bit[MAX_N+5],N;

ll bit_sum(int i)
{
	ll res = 0;
	while(i > 0)
	{
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

void bit_add(int i, ll x)
{
	while(i <= N)
	{
		//cout << "index:" << i << endl;
		bit[i] += x;
		i += i & -i;
	}
	return;
}

int main()
{
	int Q;
	cin >> N >> Q;
	rep(i,N)
	{
		ll a;
		cin >> a;
		bit_add(i+1,a);
	}
	/*
	rep(i,N)
	{
		cout << bit[i+1] << " ";
	}
	*/
	cout << endl;
	rep(i,Q)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			int p;
			ll x;
			cin >> p >> x;
			p++;
			bit_add(p,x);
			/*
			rep(i,N)
			{
				cout << bit[i+1] << " ";
			}
			cout << endl;
			*/
		}
		else
		{
			int l,r;
			cin >> l >> r;
			cout << bit_sum(r) - bit_sum(l) << endl;
		}
	}
	return 0;
}