//ABC155_C
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> Data;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;

		Data[S] += 1;
	}

	int maxv = 0;

	for (const auto& x : Data) {
		int v = x.second;
		if (v > maxv) maxv = v;
	}

	for (auto it = Data.begin(); it != Data.end(); it++) {
		if (it->second == maxv) {
			cout << it->first << endl;
		}
	}

	return 0;
}
