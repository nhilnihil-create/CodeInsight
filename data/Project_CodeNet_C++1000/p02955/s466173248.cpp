#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 505;
ll A[MAX_N];
vector<ll> d;

int main()
{
	ll N,K;
	cin >> N >> K;
	ll sum = 0;
	rep(i,N)
	{
		cin >> A[i];
		sum += A[i];
	}
	for (int i = 1; i*i <= sum; ++i)
	{
		if (sum % i == 0)
		{
			d.push_back(i);
			d.push_back(sum/i);
		}
	}
	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());
	rep(i,d.size())
	{
		ll D = d[i];
		vector<ll> B;
		ll sum2 = 0;
		rep(j,N)
		{
			B.push_back(A[j] % D);
			sum2 += A[j] % D;
		}
		sort(B.begin(), B.end());
		reverse(B.begin(), B.end());
		ll res = 0;
		for (int j = sum2 / D; j < N; ++j)
		{
			res += B[j];
		}
		if (res <= K)
		{
			cout << D << endl;
			return 0;
		}
	}
	return 0;
}