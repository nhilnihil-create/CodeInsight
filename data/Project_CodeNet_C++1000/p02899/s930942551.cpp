#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>

#define ll long long
#define pll pair<int,int>

using namespace  std;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
ll qpow(ll a, ll b, ll modd) {
	ll ans = 1, base = a;
	while (b) {
		if (b & 1) {
			ans = (ans*base) % modd;
		}
		base = (base*base) % modd;
		b >>= 1;
	}
	return ans;
}

/*A*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*B*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*C*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*D*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*E*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*F*/
vector<pll> v ;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(make_pair(tmp, i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		cout << v[i].second << ' ';
	}
}


//****************************************************************************
/*G*/

//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	ll a, b;
//	cin >> a >> b;
//
//
//
//}

//****************************************************************************
/*H*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************
/*I*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************

/*J*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************

/*K*/
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//
//
//
//}

//****************************************************************************