#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int N;

void dfs(string s, char max, int depth) {
	if(depth == N)
		cout << s << "\n";
	else {
		for(char alphabets = 'a'; alphabets <= max + 1; alphabets++)
			if(alphabets == max + 1)
				dfs(s + alphabets, alphabets, depth + 1);
			else
				dfs(s + alphabets, max, depth + 1);
	}
}

int main() {
	cin >> N;

	dfs("a", 'a', 1);
	return 0;
}
