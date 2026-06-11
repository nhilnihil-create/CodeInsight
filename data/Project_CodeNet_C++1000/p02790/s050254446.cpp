#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s = "", str = "";
	for(int i = 0; i < n; ++i)
		s += (m + '0');
	for(int i = 0; i < m; ++i)
		str += (n + '0');
	if(s < str)
		cout << s;
	else
		cout << str;
}
