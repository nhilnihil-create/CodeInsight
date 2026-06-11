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
const int N = 50000;

void player_1() {
	cout << "Ashishgup" << endl;
}

void player_2() {
	cout << "FastestFinger" << endl;
}

bool check_prime(int n) {
	if (n == 2) {
		return true;
	}
	for (int i = 2; i < min(N, n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	

	int n ;
	cin >> n;

	mk(a, n, int);
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 0 ; i < n ; i++) {
		for (int j = i + 1 ; j < n ; j++) {
			sum += (a[i] * a[j]);
		}
	}
	cout << sum;

	return 0 ;
}

