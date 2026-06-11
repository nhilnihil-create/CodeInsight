#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	int h[2], m[2], k;
	cin >> h[0] >> m[0] >> h[1] >> m[1] >> k;
	cout << h[1] * 60 + m[1] - h[0] * 60 - m[0] - k << endl;
	return 0;
}