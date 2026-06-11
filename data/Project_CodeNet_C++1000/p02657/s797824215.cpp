#include<bits/stdc++.h>
using namespace std;

#define int             long long
#define ip(x)           int x; cin>>x;
#define w(x)            int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define mod             pow(10,9)+7
#define inf             1e18
#define endl			"\n"
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >

void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {
	c_p_c();
	ip(a);
	ip(b);
	cout << a*b << endl;
	return 0;
}
