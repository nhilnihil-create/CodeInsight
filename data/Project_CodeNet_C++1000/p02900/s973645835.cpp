#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	ll A, B;
	cin >> A >> B;
	vector<ll> a, b;
	for (ll i = 1; i * i <= A; i++) {
		if (A % i == 0) {
			if (i * i != A) a.push_back(A / i);
			a.push_back(i);
		}
	}
	for (ll i = 1; i * i <= B; i++) {
		if (B % i == 0) {
			if (i * i != B) b.push_back(B / i);
			b.push_back(i);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<ll> V;
	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		while (a[i] > b[j] && j < b.size()) {
			j++;
		}
		if (j == b.size()) break;
		if (a[i] == b[j]) V.push_back(a[i]);
	}
	int ans = 1;
	for (int i = 1; i < V.size(); i++) {
		bool ok = true;
		for (int j = 1; j < i; j++) {
			if (V[i] % V[j] == 0) {
				ok = false;
				break;
			}
		}
		if (ok) ans++;
	}
	cout << ans << endl;
}
