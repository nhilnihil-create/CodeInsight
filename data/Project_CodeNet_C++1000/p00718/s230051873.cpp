#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int stoi ( string s )
{
	int m = 1, res = 0;
	for (int i = 0, I = s.size(); i < I; ++i) {
		char c = s[i];
		if (c == 'm') { res += m * 1000; m = 1; }
		else if (c == 'c') { res += m *  100; m = 1; }
		else if (c == 'x') { res += m *   10; m = 1; }
		else if (c == 'i') { res += m *    1; m = 1; }
		else          { m = c - '0'; }
	}
	return res;
}

string itos ( int n )
{
	int a[] = { 1000, 100, 10, 1 };
	char b[] = "mcxi";
	string res;
	for (int i = 0; i < 4; ++i) {
		int m = n / a[i];
		if (m >= 2) { res += (m + '0'); }
		if (m >= 1) { res += b[i];      }
		n -= m * a[i];
	}
	return res;
}

int main ( void )
{
	int n;
	while (cin >> n) {
		cin.ignore();
		for (int i = 0; i < n; ++i) {
			istringstream is;
			string str, tmp;
			int sum = 0;
			getline(cin, str);
			is.str(str);
			while (is >> tmp) {
				sum += stoi(tmp);
			}
			cout << itos(sum) << endl;
		}
	}
	return 0;
}