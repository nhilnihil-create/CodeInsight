#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> CO(N);
	for (int i = 0; i < N; i++) cin >> CO[i].first >> CO[i].second;
	sort(CO.begin(), CO.end());
	unordered_map<string, int> PairNum;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			string S = to_string(CO[j].first - CO[i].first) + "," + to_string(CO[j].second - CO[i].second);
			PairNum[S]++;
		}
	}
	int MAX = 0;
	for (const auto& pair : PairNum) MAX = max(MAX, pair.second);
	cout << N - MAX << endl;
}