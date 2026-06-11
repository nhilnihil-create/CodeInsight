#include<bits/stdc++.h>
#include<string>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define mod (ll)(1e9+7)
#define nax (ll)(1e5+1)
#define INFL LLONG_MAX
#define INF INT_MAX
#define disp(a,n,arr) for(int i=a;i<(ll)n;i++) cout << arr[i] << " "; cout << "\n";
#define check cout << "Working\n";
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pl>
#define vpi vector<pi>
#define vb vector<bool>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	FIO;

	// Write your code here


	int t = 1;
	//cin >> t;
	while (t--) {
		ll k, a, b;
		cin >> k >> a >> b;
		if (a % k == 0) {
			cout << "OK\n";
			return 0;
		} else {
			ll x = a - a % k + k;
			if (x >= a && x <= b) {
				cout << "OK\n";
				return 0;
			}
		}

		cout << "NG\n";
	}


	return 0;
}