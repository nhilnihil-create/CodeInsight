#include "bits/stdc++.h"
using namespace std;
int N;

void dfs(int count,string s) {
	if (N == s.size()) {
		cout << s <<endl;
		return;
	}
	for (int i = 0;i<=count; ++i) {
		string newS = s;
		newS += (char)(i + 'a');
		if (i != count) {
			dfs(count,newS);
		}
		else {
			dfs(count + 1,newS);
		}
	}
}

int main() {
	cin >> N;
	dfs(0,"");
	return 0;
}