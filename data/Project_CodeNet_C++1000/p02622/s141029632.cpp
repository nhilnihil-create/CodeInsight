#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	long long int min = 0;
	for (long long int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) min++;
	}
	cout << min;
	return 0;
}