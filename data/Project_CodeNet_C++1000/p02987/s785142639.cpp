#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	
	string s;
	int cnt = 0;
	cin >> s;
	sort(s.begin(), s.end());
	for (int i = 0; i < s.length()-1; i++)
		if (s[i] == s[i + 1])
			cnt++;
	if (cnt == 2)
		cout << "Yes";
	else
		cout << "No";
}
