#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
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


void aryan_p() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return;
}


int32_t main() {


	int n ;
	cin >> n;

	mk(a, 20, int);
	mk(b, 20, int);
	mk(c, 20, int);
	for (int  i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	for (int i = 0 ; i < n ; i++) {
		cin >> b[i];
	}
	for (int i = 0 ; i < n - 1 ; i++) {
		cin >> c[i];
	}

	int sum = 0;
	for (int i = 0 ; i < n ; i++) {
		int d1 = a[i];
		sum += b[d1 - 1];
		if (i != 0) {
			if (a[i] - a[i - 1] == 1) {
				sum += c[d1 - 2];
			}
		}
	}
	cout << sum;





	return 0;
}