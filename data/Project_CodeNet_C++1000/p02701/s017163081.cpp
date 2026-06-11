#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N;
vector<string> vec;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		vec.push_back(S);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	cout << vec.size() << endl;
	return 0;
}