#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;

	string r = s;
	reverse(r.begin(), r.end());

	if (r != s)
	{
		cout << "No" << endl;
		return 0;
	}

	string r1 = "";
	for (int i = 0; i < (s.size() - 1) / 2; i++)
	{
		r1.push_back(s[i]);
	}
	
	string r2 = r1;
	reverse(r2.begin(), r2.end());

	if (r1 != r2)
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	return 0;
}