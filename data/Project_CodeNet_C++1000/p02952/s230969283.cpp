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
	int n;
	cin >> n;
	int temp = floor(log10(n)) + 1;
	if (temp == 1)
		cout << n;
	else if (temp == 2)
		cout << "9";
	else if (temp == 3)
		cout << 9 + (n - 100 + 1);
	else if (temp == 4)
		cout << 9 + (900);
	else if (temp == 5)
		cout << 909 + (n - 10000 + 1);
	else if (temp == 6)
		cout << "90909";
}
