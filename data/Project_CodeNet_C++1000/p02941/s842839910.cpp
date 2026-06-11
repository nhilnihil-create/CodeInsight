#include <cstdio>
#include <algorithm>  
#include <bitset>
#include <cassert>
#include <ctime>  
#include <cmath>  
#include <cstdlib>  
#include <cstring>  
#include <functional>  
#include <iostream>  
#include <deque>  
#include <stack>
#include <queue>  
#include <vector>  
#include <map>  
#include <set>  
#include <string>  
#include <unordered_map>  
#include <unordered_set>  
#pragma warning(disable:4996)

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, int> pdi;

const int INF = 1e9;
const int MAXN = 3e5 + 5;
const int SZ = 1 << 19;

ll N, A[MAXN], B[MAXN], ans;
priority_queue<pll> pq;

void wrong() {
	cout << -1;
	exit(0);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i=1; i<=N; i++) cin >> A[i];
	for(int i=1; i<=N; i++) cin >> B[i];

	A[0] = A[N]; A[N+1] = A[1];
	B[0] = B[N]; B[N+1] = B[1];

	for(int i=1; i<=N; i++) {
		if(A[i] > B[i]) wrong();
		if(A[i] < B[i]) pq.push(pii(B[i], i));
	}

	while(!pq.empty()) {
		int i = pq.top().se; pq.pop();

		if(B[i] - A[i] < B[i-1] + B[i+1]) wrong();

		int cnt = (B[i] - A[i]) / (B[i-1] + B[i+1]);
		B[i] -= cnt * (B[i-1] + B[i+1]);
		ans += cnt;

		if(A[i] < B[i]) pq.push(pii(B[i], i));
		if(i == N) B[0] = B[N];
		if(i == 1) B[N+1] = B[1];
	}
	cout << ans;
}
