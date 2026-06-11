#include<vector>
#include<iostream>
using namespace std;
int main() {
	vector<int> map;
	map.push_back(0);
	char code;
	while (cin >> code) {
		if (code == '\\')map.push_back(map.back() - 1);
		else if(code=='/') map.push_back(map.back() + 1);
		else map.push_back(map.back());
	}
	vector<int>water;
	int answer=0;
	vector<int>::iterator he,he2;
	for (he = map.begin(); he != map.end()-1; ++he) {
		if (*he > *(he + 1)) {
			for (he2 = he+1; he2 != map.end()&&*he2 != *he; ++he2);
			if (he2 == map.end())continue;
			water.push_back(0);
			for (; he != he2; ++he) {
				water.back() += *he2 - *he;
			}
			answer += water.back();
			--he;
		}
	}
	cout << answer << endl<<water.size();
	for (he = water.begin(); he != water.end(); ++he) {
		cout << ' ' << *he;
	}
	cout << endl;
	return 0;
}