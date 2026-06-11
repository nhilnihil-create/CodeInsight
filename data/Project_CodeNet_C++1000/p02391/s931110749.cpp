#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x,y;
	cin >> x >> y;
	string ans = (x < y) ? "a < b" : x == y ? "a == b" : "a > b";
	cout << ans << endl;
	return 0;
}