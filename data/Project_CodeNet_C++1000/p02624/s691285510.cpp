#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll M=1000010;

int main() {
	ll N, ans=0;
	set<ll> st;

	cin >> N;
	vector <ll> f(N+1);

	for (ll x = 1; x <= N;x++){
		f[x] = x*(N/x)*(N/x + 1) / 2;
		ans += f[x];
	}

	cout << ans << endl;

	return 0;
}