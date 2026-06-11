#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int buf = n % 10;
	if (buf == 3)cout << "bon" << endl;
	else if (buf == 0 || buf == 1 || buf == 6 || buf == 8)cout << "pon" << endl;
	else cout << "hon" << endl;
	return 0;
}