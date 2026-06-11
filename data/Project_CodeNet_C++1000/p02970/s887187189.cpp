#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
typedef pair<int, int> P;

signed main() {
	int n, d; cin >> n >> d;
	d = d + d + 1;
	cout << (n + d - 1) / d << endl;
}