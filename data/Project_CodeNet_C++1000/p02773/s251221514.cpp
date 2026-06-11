#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N; cin >> N;


	map<string, int> S;
	set<string> SET;
	int MAX = 0;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		SET.insert(s);
		S[s] += 1;	
		MAX = max(MAX, S[s]);
	}

	for (string x : SET) {
		if (MAX == S[x]) {
			cout << x << endl;
		}
	}
	


	return 0;
}
