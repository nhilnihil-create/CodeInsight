#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll h[100005];
int main() {
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i < n; i++) {
		if (h[i] > h[i - 1]) {
			h[i]--;
		}
		else if (h[i] < h[i - 1]) {
			cout << "No" << endl;
			return 0;
		}
		
	}
	cout << "Yes" << endl;
	return 0;
}
