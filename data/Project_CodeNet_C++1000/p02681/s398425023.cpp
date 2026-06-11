#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	string s, t;
	cin >> s >> t;
	if (t.substr(0, s.size()) == s)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}