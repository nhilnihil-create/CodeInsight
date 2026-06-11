#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define MOD 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(var) (var).begin(), (var).end()
#define MAXX 9000000000000000000
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> > 
#define vvpi vector<vector<pair<int,int> > >

struct comp
{	
	bool operator() (int a, int b) const
	{
		return a > b;
	}
};

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int n,m,i,j,x,y;
	cin >> n >> m;
	multiset<int, comp> arr;
	while(n--)
	{
		cin >> x;
		arr.insert(x);
	}

	// cout << m << endl;

	while(m--)
	{
		int x = *arr.begin();
		arr.erase(arr.begin());
		arr.insert(x / 2);
	}

	int ans = 0;

	for(auto it : arr)
	{
		ans += it;
	}

	cout << ans ;
	
	return 0;
}