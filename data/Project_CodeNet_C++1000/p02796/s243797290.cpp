#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<typeinfo>
#include<queue>
using namespace std;
int next_combination(int sub) {
	int x = sub & -sub, y = sub + x;
	return (((sub & ~y) / x) >> 1) | y;
}
int main() {
	int N;
	cin >> N;
	vector<int> x(N), l(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> l[i];
	}
	vector<pair<int, int>> arm(N);
	for (int i = 0; i < N; i++) {
		arm[i].first = x[i] + l[i];
		arm[i].second = x[i] - l[i];
	}
	sort(arm.begin(), arm.end());
	int count = 1;
	int sec_end = arm[0].first;
	for (int i = 0; i < N; i++) {
		if (sec_end <= arm[i].second) {
			sec_end = arm[i].first;
			count++;
		}
	}
	cout << count<<endl;
}