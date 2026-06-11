#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	int p[100001];
	string s[100001];
	set<int> ac;
	for (int i = 0; i < M; i++) {
		cin >> p[i] >> s[i];
		if (s[i] == "AC") ac.insert(p[i]);
	}

	set<int> correct;
	int ans = 0;
	int pena = 0;
	for (int i = 0; i < M; i++) {
		if (s[i] == "AC") {
			if (correct.find(p[i]) == correct.end()) {
				correct.insert(p[i]);
				ans++;
			}
		} else {
			if (correct.find(p[i]) == correct.end() && ac.find(p[i]) != ac.end()) {
				pena++;
			}
		}
	}
	printf("%d %d\n", ans, pena);

	return 0;
}
