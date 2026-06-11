#pragma warning(disable:4996)
#include<iostream>
#include<stdio.h>
#include<sstream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<limits.h>
using namespace std;
using ll = long long int;
int main() {
	ll N, K, ans = 0;
	vector<ll> rec;
	cin >> N >> K;
	rec = vector<ll>(N);
	for (int i = 0; i < N; ++i)
		cin >> rec[i];
	sort(rec.begin(), rec.end(), greater<ll>());
	for (int i = K; i < N; i++)
		ans += rec[i];
	cout << ans;
	return 0;
}