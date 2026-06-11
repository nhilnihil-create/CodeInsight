#include <iostream>
using namespace std;

int main() {
	string s[]  = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	string str;
	cin >> str;
	int ptr = 0;
	for(string cur : s) {
		if(cur == str) {
			break;
		}
		++ptr;
	}
	++ptr;
	int answer = 1;
	for(int i = ptr; i < 7; ++i) {
		i %= 7;
		if(s[i] == "SUN")
			break;
		++answer;
	}
	cout << answer;
}
