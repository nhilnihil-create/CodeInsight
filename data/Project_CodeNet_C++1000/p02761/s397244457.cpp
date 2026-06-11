#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>
using namespace std;

namespace {

}

int main()
{
	int N, M;

	cin >> N >> M; // Mは行数らしい。

	vector<int> c(3, 0);
	vector<int> s(3, 0);
	vector<bool> setflg(3, false);
	for (int i = 0; i < M; ++i){
		int first, second;
		cin >> first >> second;
		if (setflg[first-1]){
			if (s[first-1] != second){
				cout << -1 << endl;
				return 0;
			}
		}
		setflg[first - 1] = true;
		s[first-1] = second;
	}

	if (N == 1){
		if (setflg[0]){
			cout << s[0] << endl;
			return 0;
		}
		else {
			cout << 0 << endl;
			return 0;
		}
	}
	else {
		if (setflg[0]){
			if (s[0] == 0){
				cout << -1 << endl;
				return 0;
			}
		}
		else {
			s[0] = 1;
		}
		cout << s[0];

		for (int i = 1; i < N; ++i){
			if (setflg[i] == false){
				s[i] = 0;
			}
			cout << s[i];
		}
		
		cout << endl;
		return 0;
	}
}
