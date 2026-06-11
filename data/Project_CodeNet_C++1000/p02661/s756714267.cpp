#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 922337203685477;
const ll mininf = -922337203685477;
const ll nax = 2e5 + 5;

ll n, a[nax], b[nax];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	if(n & 1){
		ll mid = n / 2;
		cout << b[mid] - a[mid] + 1 << '\n';
	}
	else{
		ll mid = n / 2;
		ll mid2 = n / 2 - 1;
		cout << (b[mid] + b[mid2]) - (a[mid] + a[mid2]) + 1 << '\n';
	}
}
