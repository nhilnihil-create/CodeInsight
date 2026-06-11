#include <bits/stdc++.h>
// g++ test.cpp && ./a.out < in
#pragma GCC optimize("O3")
using namespace std;
#define fi first
#define se second
#define pb push_back
#define loop(i, a, b) for (int i=a; i<(b); i++)
typedef long long ll;
typedef pair<int,int> pi;
const int INF = 1e9;
const int MOD = 1000000007;



void test_case() {
	int n; cin>>n;
	int ans = 0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i&1 && x&1) ans++;
	}
	cout<<ans<<endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		test_case();
	}
	return 0;
}