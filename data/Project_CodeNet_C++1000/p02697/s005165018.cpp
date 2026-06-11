#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll mininf = -922337203685477;
const ll nax = 0;

ll n, k, low, up;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
	
	cin >> n >> k;
	low = k - k / 2;
	up = k / 2;
	for(ll i = 1; i <= low; i++){
		cout << i << " " << low * 2 - i + 1 << '\n';
	}
	for(ll i = 1; i <= up; i++){
		cout << low * 2 + i << " " << low * 2 + up * 2 - i + 2 << '\n';
	}
}
