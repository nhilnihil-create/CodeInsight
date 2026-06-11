#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N; cin >> N;

	string s,t; cin >> s >> t;

	string ans = "";
	for (int i = 0; i < N; i++) {
		ans += s[i];
		ans += t[i];
	}
	cout << ans << endl;

	return 0;
}
