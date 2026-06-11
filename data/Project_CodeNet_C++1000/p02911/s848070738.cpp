#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;

int arr[100005];
void solve() {
	int n, k, q;
	cin >> n >> k >> q;
	for(int i = 0; i < q; ++i) {
		int x;
		cin >> x; 
		arr[x]++;
		}
		for(int i = 1; i <= n; ++i) {
			if(q - arr[i] < k) cout << "Yes" << endl;
			else cout << "No" << endl;
			}
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

