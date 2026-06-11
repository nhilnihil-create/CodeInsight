#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(i=0; i<n; i++)
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i, k;
	priority_queue <ll> q;
	ll temp;
	cin >> t >> k;
	fo(i, t) {
		cin >> temp;
		q.push(temp);
	}
	fo(i, k) {
		temp = q.top();
		q.pop();
		q.push(temp / 2);
	}
	temp = 0;
	while (!q.empty()) {
		temp += q.top();
		q.pop();
	}
	cout << temp;
	return 0;
}