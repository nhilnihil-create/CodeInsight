#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	unordered_map<string, int> order;
	vector<int> times(N,0);
	for (int i = 0; i < N; i++) {
		string title;
		int time;
		cin >> title >> time;
		times[i] = time;
		order[title] = i;
	}

	string X;
	cin >> X;
	int sleep_first = order[X] + 1;
	int ans = 0;
	for (int i = sleep_first; i < N; i++) ans += times[i];
	cout << ans << endl;
}

