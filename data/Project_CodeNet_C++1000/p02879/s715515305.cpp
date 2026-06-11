#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int A, B;
	cin >> A >> B;
	if(1 <= A && A <= 9 && 1 <= B && B <= 9)
		cout << A * B;
	else
		cout << -1;
	return 0;
}