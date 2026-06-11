#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 210000
ll P[N], pos[N];
signed main () {
	memset(pos, -1, sizeof(pos));
	ll n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)  {
		cin >> P[i];
	}
	ll pt = 1;
	vector<ll> v;
	while(pos[pt] == -1) {
		pos[pt] = v.size();
		v.push_back(pt);
		pt = P[pt];
	}
	int c = v.size() - pos[pt];
	int l = pos[pt];
	if(k < l) {
		cout << v[k] << endl;//未进环 
	}
	else {
		k -= l;k %= c;
		cout << v[l + k] << endl;
	}
	
	return 0;
} 