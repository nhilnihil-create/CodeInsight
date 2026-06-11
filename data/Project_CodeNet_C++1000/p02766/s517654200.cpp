#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(vs) vs.begin(), vs.end()
using ii = pair<int, int>;
using ll = long long;

int32_t main(){
	ios::sync_with_stdio(0);	
	ll n, k;
	cin >> n >> k;
	ll res = log(n)/log(k)+1;
	cout << res << endl;
}
