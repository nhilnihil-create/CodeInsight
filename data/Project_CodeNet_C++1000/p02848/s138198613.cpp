#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string s;
	cin >> N >> s;
	int len = s.length();
	for(int i = 0 ; i < len ; i++){
		char c = ((s[i] - '@' + N)%26) + '@';
		c = c == '@' ? 'Z' : c;
		s[i] = c;
	}
	cout << s << '\n';
	return 0;
}