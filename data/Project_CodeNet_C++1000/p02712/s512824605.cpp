#include<bits/stdc++.h>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define pf 				push_front
#define mp              make_pair
#define pii             pair<int,int>
#define MAX 			1000000
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
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_p_c()
{
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
bool complete(int satisfied[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (satisfied[i] != 1)
			return false;
	}
	return true;
}
void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

bool f(int x, int y)
{
	return x > y;
}
int Lucky(int n)
{
	int c = 0;
	while (n != 0)
	{
		int r = n % 10;
		if (r == 4 || r == 7)
			c++;
		n /= 10;
	}
	return c;
}
bool isPrime(int x)
{
	int i;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
int32_t main()
{
	
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			continue;
		else
			sum += i;
	}
	cout << sum;
}

