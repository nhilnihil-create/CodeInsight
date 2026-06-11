/**
**	author : Raghav
**	codechef:raghav_456
**	codeforces:raghavramola7
**/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long int
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void Raghav()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n) + 1; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
int32_t main()
{
	Raghav();
	int n, m, sum = 0;
	cin >> n >> m;
	int a[m];
	for (auto i : a)
	{
		cin >> i;
		sum += i;
	}
	if (sum > n)
		cout << -1;
	else
		cout << n - sum;



	return 0;
}