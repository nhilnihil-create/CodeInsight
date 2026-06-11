#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#define task ""
using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 2;
int n;
ll ans;

void Read(){
	cin >> n;
	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		if(u > v)
			swap(u, v);
		ans -= 1ll * u * (n - v + 1);
	}
}

void Solve(){
	cout << ans + 1ll * (n + 1) * (n + 2) * n / 6ll;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Read();
	Solve();
}
