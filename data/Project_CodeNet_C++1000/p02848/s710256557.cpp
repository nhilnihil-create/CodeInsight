#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N;
	string S;
	cin >> N >> S;

	for(int i = 0; i < S.size(); i++) {
		S[i] = (char)((int)S[i] + N);
		if(S[i] > 'Z') S[i] = (char)((int)S[i] - 26);
	}
	cout << S << "\n";
}