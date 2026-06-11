#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	vector<ll> u(n), v(n);
	rep(i, n - 1) {
		cin >> u[i] >> v[i];
		if(u[i] > v[i]) swap(u[i], v[i]);
	}

	ll vcnt = (n+2) * (n+1) * n / 3 / 2 / 1;

	ll ecnt = 0;
	rep(i, n){
		ecnt += u[i] * (n - v[i] + 1);
	}

	cout << vcnt - ecnt << endl;
}
