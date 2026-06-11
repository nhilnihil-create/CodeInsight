#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

bool cmp(const pair<ll, ll>& p, const pair<ll, ll>& q) {
	if (p.second != q.second)
		return p.second > q.second;
	else
		return p.first > q.first;
}

int main(void) {
	ll N, M;
	cin >> N >> M;

	vector<pair<ll, ll>> job(N);
	for (int i = 0; i < N; i++) {
		cin >> job[i].first >> job[i].second;
	}

	sort(job.begin(), job.end(), cmp);
	
	set<int> day;
	for (int i = 0; i <= M; i++)
		day.insert(i);

	ll ans = 0;
	for (int i = 0; !day.empty() && i < N; i++) {
		auto it = day.lower_bound(job[i].first);
		if (it != day.end()) {
			ans += job[i].second;
			day.erase(*it);
		}
	}

	cout << ans << endl;
}