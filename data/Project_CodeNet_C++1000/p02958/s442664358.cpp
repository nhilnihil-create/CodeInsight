#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	cin >> N;
	int p[N];
	for(int i = 0; i < N; i++) cin >> p[i];

	int wrong = 0;
	for(int i = 0; i < N; i++)
		if(i + 1 != p[i]) wrong++;
	if(wrong <= 2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}