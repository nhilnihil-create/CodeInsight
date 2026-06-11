#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;

int main() {
	ll n, k, s;
	cin >> n >> k >> s;
	if (s < n) {
		rep(i, k) cout << s << " ";
		rep(i, n - k)cout << 1000000 << " ";
	}
	else {
		rep(i, k) cout << s << " ";
		rep(i, n - k)cout << 1 << " ";
	}
}