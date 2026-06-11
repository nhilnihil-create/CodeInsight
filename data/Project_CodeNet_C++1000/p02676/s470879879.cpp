#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	if (s.size() <= k)cout << s << endl;
	else cout << s.substr(0, k) + "..." << endl;
	return 0;
}