#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<iostream>
#include<algorithm>//next_permutation

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<string>s(N);
	vector<int>t(N);
	for (int i = 0;i < N;i++) {
		cin >> s.at(i) >> t.at(i);
	}
	string X;
	cin >> X;
	bool F = false;
	int answer = 0;
	for (int i = 0;i < N;i++) {
		if (F) {
			answer += t.at(i);
		}

		if (s.at(i) == X && F == false) {
			F = true;
		}
	}
	cout << answer << endl;
}
