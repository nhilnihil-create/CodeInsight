#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 1000005;
ll A[MAX_N],Ac[MAX_N],c[MAX_N],D[MAX_N];
vector<ll> pri;

ll mygcd(ll a, ll b)
{
	if (b == 0) return a;
	return mygcd(b,a%b);
}

int main()
{
	int N;
	cin >> N;
	ll stwise = 0;
	rep(i,N)
	{
		cin >> A[i];
		Ac[A[i]]++;
		if (i == 0) stwise = A[i];
		else stwise = mygcd(stwise,A[i]);
		//cout << stwise << " ";
	}
	if (stwise != 1)
	{
		cout << "not coprime" << endl;
		return 0;
	}
	else
	{
		D[0] = 0;
		D[1] = 1;
		for (int i = 2; i < MAX_N; ++i)
		{
			if (D[i] == 0)
			{
				D[i] = i;
				for (int j = 2*i; j < MAX_N; j += i)
				{
					if (D[j] == 0) D[j] = i;
				}
			}
		}

		rep(i,N)
		{
			ll temp = A[i];
			while(temp > 1)
			{
				int d = D[temp];
				c[d]++;
				while(temp % d == 0)
				{
					temp /= d;
				}
			}
			//cout << "a";
		}

		for (int i = 2; i < MAX_N; ++i)
		{
			//cout << c[i] << " ";
			if (c[i] > 1)
			{
				cout << "setwise coprime" << endl;
				return 0;
			}
		}
		cout << "pairwise coprime" << endl;
	}
	return 0;
}