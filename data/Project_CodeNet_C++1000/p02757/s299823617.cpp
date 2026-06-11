#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	long long answer = 0;
	if(p == 2) {
		for(int i = 0; i < n; ++i)
			if((s[i] - '0') % 2 == 0)
				answer += i + 1;
	}
	else if(p == 5) {
		for(int i = 0; i < n; ++i)
			if((s[i] - '0') % 5 == 0)
				answer += i + 1;
	}
	else {
		map<int, int> suffix;
		++suffix[0];
		int power = 1, cur = 0;
		for(int i = n - 1; ~i; --i) {
			cur = (cur + power * (s[i] - '0')) % p;
			answer += suffix[cur];
			++suffix[cur];
			power = power * 10 % p;
		}
	}
	cout << answer;
}
