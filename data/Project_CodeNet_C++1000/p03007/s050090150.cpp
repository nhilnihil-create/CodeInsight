//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
	int N;
	cin >> N;
	vector<int> Ais;
	for (int i = 0; i < N; i++) {
		int Ai;
		cin >> Ai;
		Ais.push_back(Ai);
	}
	sort(Ais.begin(), Ais.end());
	vector<int> add;
	vector<int> subtract;
	for (int i = 0; i < Ais.size(); i++) {
		int Ai = Ais[i];
		if (i == 0) {
			subtract.push_back(Ai);
		} else if (i == Ais.size() - 1) {
			add.push_back(Ai);
		} else {
			if (Ai >= 0) {
				add.push_back(Ai);
			} else {
				subtract.push_back(Ai);
			}
		}
	}
	int add_sum = 0;
	for (int n : add) {
		add_sum += n;
	}
	int subtract_sum = 0;
	for (int n : subtract) {
		subtract_sum += n;
	}
	cout << add_sum - subtract_sum << endl;
	int value = 0;
	if (add.size() >= 2) {
		value = subtract.back();
		subtract.pop_back();
		while (add.size() >= 2) {
			cout << value << " " << add.back() << endl;
			value = value - add.back();
			add.pop_back();
		}
		cout << add.back() << " " << value << endl;
		value = add.back() - value;
	} else {
		value = add[0];
	}
	while (subtract.size() > 0) {
		cout << value << " " << subtract.back() << endl;
		value = value - subtract.back();
		subtract.pop_back();
	}
}
