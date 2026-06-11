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
const int Max = 1e7;
int32_t main()
{
	//c_p_c();
	int a, b, c;
	cin >> a >> b >> c;
	if ( (c - (a - b)) > 0)
		cout << c - a + b;
	else
		cout << "0";
}