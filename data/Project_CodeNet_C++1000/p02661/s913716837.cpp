#include <bits/stdc++.h>
#include <vector>
#include<iterator>
#include<utility>
#include<math.h>
#include <cmath>
#include<algorithm>


using namespace std;

typedef long long ll; // %lld
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mod (pow(10,9)+7);
#define PB push_back
#define POB pop_back
#define MP make_pair
#define itri std::vector<int>::iterator
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)


void showpq(vector <ll> gq)
{
	vector <ll> g = gq;
	reverse(g.begin(), g.end());
	while (!g.empty())
	{
		cout << g.back() << " ";
		g.pop_back();
	}
	cout << '\n';
}

double findMedian(vector <ll> a, ll n)
{
	// First we sort the array
	//sort(a, a + n);
	sort(a.begin(), a.end());

	// check for even case
	if (n % 2 != 0)
		return (long double)a[n / 2];

	return (long double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inno.in", "r", stdin);
	freopen("ottu.txt", "w", stdout);
#endif

	ll n, L, H, m, diff;

	cin >>  n;
	m = n;
	vector<ll> low, high;

	while (n--)
	{
		cin >> L >> H ;
		low.PB(L);
		high.PB(H);
	}

	sort(low.begin(), low.end());
	sort(high.begin(), high.end());

	//diff = ll(findMedian(high, m) - findMedian(low, m));

	if (m % 2 != 0)
	{
		cout <<  ( ( high[(m - 1) / 2] - low[(m - 1) / 2] )  + 1)  << endl;
	}
	if (m % 2 == 0)
	{
		cout <<  (  ( ( high[m / 2] + high[(m / 2) - 1] )  -  ( low[m / 2] + low[(m / 2) - 1] )  ) + 1)  << endl;
	}


	return 0;
}