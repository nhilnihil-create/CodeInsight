#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	string S;
	cin >> S;
	bool ans = false;
	for(int i = 1; i < S.size(); i++)
		if(S[i - 1] == S[i]) ans = true;

	if(ans)
		cout << "Bad";
	else
		cout << "Good";
	return 0;
}
