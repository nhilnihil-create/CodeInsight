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
		return a[ (n - 1) / 2];

	return   (  ( a[n / 2] + a[(n / 2) - 1] )   );
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
	diff = ll(findMedian(high, m) - findMedian(low, m));
	if (m % 2 == 0)
	{
		cout <<  ((diff) + 1)  << endl;
	}
	if (m % 2 != 0)
	{
		cout <<  (diff + 1)  << endl;
	}


	return 0;
}
