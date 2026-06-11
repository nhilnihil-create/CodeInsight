#include<bits/stdc++.h>
using namespace std;

// #define ff              first
// #define ss              second
// #define int             long long
// #define pb              push_back
// #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define mii             map<int,int>
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int> >
// #define setbits(x)      __builtin_popcountll(x)
// #define zrobits(x)      __builtin_ctzll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x; cin>>x; while(x--)


void aryan_p() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return;
}




int32_t main() {


	int n , k ;
	cin >> n >> k;
	int c = 0 ;
	while (n--) {
		int i ;
		cin >> i;
		if (i >= k) {
			c++;
		}
	}
	cout << c;


	return 0;
}
