#include <iostream>
#include <map>
using namespace std;

int main() {
	string s;
	cin >> s;
	map<int, int> suffix;
	++suffix[0];
	int power = 1, cur = 0, m = 2019, n = s.size();
	long long answer = 0;
	for(int i = n - 1; ~i; --i) {
		cur = (cur + (s[i] - '0') * power) % m;
		answer += suffix[cur];
		++suffix[cur];
		power = power * 10 % m;
	}
	cout << answer;
}
