#include <iostream>
#include <string>
#include <cctype>
using namespace std;



int main()
{
	int  n;
	string str1, str2;

	cin >> n;

	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		if (str1 > str2)cnt1 += 3;
		else if (str1 < str2)cnt2 += 3;
		else if (str1 == str2)cnt1 += 1, cnt2 += 1;
	}
	cout << cnt1 << " " << cnt2 << endl;
}