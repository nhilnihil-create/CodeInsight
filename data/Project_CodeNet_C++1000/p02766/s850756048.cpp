#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define be(v) v.begin(), v.end()
typedef long long ll;
typedef vector<int> vint;
#define scout cout << fixed << setprecision(5) 
ll INF = 1e9;
ll mod = 1e9+7;

int main() {
	int n,k; cin >> n >> k;
	int ans=0;
	while(n>0) {
		n/=k;
		ans++;
	}
	cout << ans << endl;
}