#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
ll a[MAX_N],B[100000];

ll mygcd(ll a, ll b)
{
	if (b == 0) return a;
	else return mygcd(b,a%b);
}

ll lcm(ll a, ll b)
{
	return a / mygcd(a,b) * b;
}

int main()
{
	ll N,M;
	cin >> N >> M;
	rep(i,N)
	{
		cin >> a[i];
		a[i] /= 2;
	}
	ll temp = a[0];
	int p = 0;
	while (temp % 2 == 0)
	{
		p++;
		temp /= 2;
	}
	rep(i,N-1)
	{
		temp = a[i+1];
		int pp = 0;
		while(temp % 2 == 0)
		{
			pp++;
			temp /= 2;
		}
		if (pp != p)
		{
			cout << "0" << endl;
			return 0;
		}
	}

	ll L = a[0];
	rep(i,N-1)
	{
		L = lcm(L,a[i+1]);
		//cout << L << endl;
		if (L > M)
		{
			cout << "0" << endl;
			return 0;
		}
	}
	cout << M/L - M/(L*2) << endl;
	return 0;
}