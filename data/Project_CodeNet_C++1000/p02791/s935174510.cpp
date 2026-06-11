#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;



void solve() {
	int n;
	ll cnt = 1;
	cin >> n;
	int arr[n];
	int m_value = 1e9;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
		if(!i) continue;
		m_value = min(m_value, arr[i - 1]);
		if(arr[i] <= m_value) cnt++;
		}
		cout << cnt << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 
