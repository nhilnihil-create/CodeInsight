#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define initdp(a, b)  for (int i = 0; i <= a; i++)   for (int j = 0; j <= b; j++) dp[i][j] = -1;
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repd(i, n) for (int i = n - 1; i >= 0; i--)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define inf 1000000001
#define inf1 1000000000000000001
#define mod 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 1000005
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<int,int>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
using namespace std;


void solve(){
    

  ll n, k, ans = LONG_MAX;
	cin >> n >> k;


	vector<ll> a(n);
	rep(i,n) {
		cin >> a[i];
		a[i]--;
	}
 
	ll curr = 0;
	vector<ll> vis(n, -1);
	vis[0] = 0;
	for (ll i = 1; i <= k; ++i) {
 
		if (vis[a[curr]] >= 0) {
			ll num = (k - i) % (i - vis[a[curr]]);
			curr = a[curr];
			for (ll j = 0; j < num; j++) {
				curr = a[curr];
			}
			break;
		}


		else {
			curr = a[curr];
			vis[curr] = i;
		}
	}


	cout << curr + 1 << endl;


 
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}