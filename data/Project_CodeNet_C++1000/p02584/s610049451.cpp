#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<functional>
#include<string>
#include<vector>
#include<cstring>
#include<utility>
#include<set>
#include<map>

#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 2e9
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
const double PI = acos(-1);

using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//	freopen("input.txt", "r", stdin);
	
	ll X, K, D; cin >> X >> K >> D;
	if (K <= abs(X) / abs(D)) {
		cout << abs(X) - K*abs(D);
	}
	else {
		K -= abs(X) / abs(D);
		X = abs(X) % abs(D);
		if (K % 2) cout << abs(X - abs(D));
		else cout << X;
	}

}
