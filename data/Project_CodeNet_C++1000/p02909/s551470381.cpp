#include <iostream>
using namespace std;

int main() {
	string s[] = {"Sunny", "Cloudy", "Rainy"};
	string str;
	cin >> str;
	int idx;
	for(int i = 0; i < 3; ++i)
		if(str == s[i])
			idx = i;
	++idx;
	idx %= 3;
	cout << s[idx];
}
