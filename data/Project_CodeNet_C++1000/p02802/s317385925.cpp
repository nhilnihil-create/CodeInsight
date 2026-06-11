#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<bool> AC(N, false);
	int ok = 0, penalty = 0;
	vector<int> debt(N, 0);
	for (int i = 0; i < M; i++) {
		int p;
		string S;
		cin >> p >> S;
		p--;
		if (!AC[p]) {
			if (S == "AC") {
				AC[p] = true;
				ok++;
				penalty += debt[p];
				debt[p] = 0;
			}
			if (S == "WA") debt[p]++;
		}
	}
	cout << ok << " " << penalty << endl;
	
	return 0;
}