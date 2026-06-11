#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
double condition = 0.0;

bool kaibun(string S, int start, int length)
{
	string tmp1, tmp2;
	tmp1 = S.substr(start, length);
	tmp2 = tmp1;
	reverse(tmp2.begin(), tmp2.end());
return tmp1 == tmp2;
}

void func()
{
	string S;
	cin >> S;


	int l = S.length();
	if (kaibun(S,0,l)
		&& kaibun(S, 0, (l-1)/2)
		&& kaibun(S, (l + 3) / 2  - 1, l- (l + 3) / 2 + 1))
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
}

int main() {
//	while(1)
	func();
	return 0;
}
