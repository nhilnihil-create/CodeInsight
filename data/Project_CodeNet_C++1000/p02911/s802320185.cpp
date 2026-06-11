#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;

int main() {
	int N;
	ll K;
	int Q;
	cin >> N >> K >> Q;
	vector<int> A(Q);
	for (int i = 0; i < Q; i++) cin >> A[i];
	vector<ll> p(N+1, K-Q);
	for (int i = 0; i < Q; i++) {
		p[A[i]]++;
	}
	for (int i = 1; i <= N; i++) {
		if (p[i] > 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
