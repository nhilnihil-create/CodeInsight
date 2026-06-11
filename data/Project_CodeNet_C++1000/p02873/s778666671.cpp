#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}

int main() {
	string S; 
	cin >> S;
	int N = (int)S.length();
	vector<int> vec(N+1, 0);
	vector<int> zeroP;

	// seach zeroP
	if (S[0] == '<') zeroP.push_back(0);
	if (S[N - 1] == '>') zeroP.push_back(N);
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == '>' && S[i + 1] == '<') zeroP.push_back(i + 1);
	}

	//sweep right
	for (int i : zeroP) {
		vec[i] = max(vec[i],0);
		for (int move = 0; i + move < N && S[i + move] == '<'; move++) {
			vec[i + move+1] = max(vec[i + move + 1], move+1);
		}
	}
	//sweep left
	for (int i : zeroP) {
		for (int move = 1; i - move >= 0 && S[i - move] == '>'; move++) {
			vec[i - move] = max(move, vec[i - move]);
		}
	}


	print(accumulate(vec.begin(), vec.end(), 0LL));

}