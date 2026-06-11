#include <bits/stdc++.h>
using namespace std;
 
template<typename T>
class BIT
{
//bit[x]
//manage range of bit[x] is (x & -x)
//
public:
	static const int n = 10000;
	T bit[n] = {};
	void add(int a, T w)
	{
		for (int x = a; x <= n; x += x & -x)
		{
			bit[x] += w;
		}
	}
	T sum(int a)
	{
		T ret = 0;
		for (int x = a; x > 0; x -= x & -x)
		{
			ret += bit[x];
		}
		return ret;
	}
};
 
long long int wa(long long int a)
{
	return (a*(a+1))/2;
}
 
int main()
{
	long long int n, k;
	cin >> n >> k;
	int A[2001], B[2001];
	for (int i = 0; i < n; ++i)
	{
		cin >> B[i];
		A[i] = 2000 - B[i] + 1;
	}
	long long int tentou[2001];
	long long int migi[2001];
	long long int ti = wa(k) % 1000000007;
	long long int to = wa(k - 1) % 1000000007;
	BIT<long long int> BT;
	BIT<long long int> saisho;
	for (int i = 0; i < n; ++i)
	{
		tentou[i] = BT.sum(A[i] - 1);
		BT.add(A[i], 1);
	}
	for (int i = n - 1; i >= 0; --i)
	{
		migi[i] = saisho.sum(A[i] - 1);
		saisho.add(A[i], 1);
	}
	long long int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += ((ti * tentou[i])%1000000007 + (to * migi[i])% 1000000007)% 1000000007 ;
	}
	cout << ans % 1000000007 << endl;
}