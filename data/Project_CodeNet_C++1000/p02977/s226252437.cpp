#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, x = 0;
int g(int a) {
	if(a==1) return n+2;
	if(a==2) return n+3;
	return a&1?n+1+a:a;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if(n<3||(n&-n)==n) return cout << "No", 0;
	cout << "Yes\n";
	cout << 3 << " " << n+1 << "\n";
	for(int i = 1; i < 3; i++) {
		cout << i << " " << i+1 << "\n";
		cout << n+i << " " << n+i+1 << "\n";
	}
	if(n==3) return 0;
	int a = 3;
	for(int i = a+1; i < n; i+=2) {
		cout << n+1 << " " << i << "\n";
		cout << i << " " << i+1 << "\n";
		cout << n+1 << " " << n+i+1 << "\n";
		cout << n+i+1 << " " << n+i << "\n";
	}
	if(!(n&1)) {
		int x = n&-n, on = n;
		n-=x;
		x^=1;
		if(((x&1)&&x!=3)||x==2)x+=on;
		if(((n&1)&&n!=3)||n==2)n+=on;
		cout << on << " " << x << "\n";
		cout << 2*on << " " << n << "\n";
	}
	return 0;
}
