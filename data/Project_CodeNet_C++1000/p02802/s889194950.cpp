#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, M;
int A[1 << 18];
bool used[1 << 18];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a; string b; cin >> a >> b;
		if (b == "WA" && used[a] == false) { A[a] += 1; }
		if (b == "AC") { used[a] = true; }
	}

	int v1 = 0, v2 = 0;
	for (int i = 1; i <= N; i++) {
		if (used[i] == false) continue;
		v1 += 1; v2 += A[i];
	}
	cout << v1 << " " << v2 << endl;
	return 0;
}