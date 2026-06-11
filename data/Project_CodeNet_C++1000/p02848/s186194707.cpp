#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] + n > 90) {
			s[i] = s[i] - 26;
		}
		s[i] = s[i] + n;
	}
	cout << s << endl;
}