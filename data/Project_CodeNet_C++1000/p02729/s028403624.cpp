#include<iostream>
#include <string>
using namespace std;
int main()
{
	int iodd = 0;
	int iedge = 0;
	int patternsum = 0;
	cin >> iodd >> iedge;
	//偶数ゼロの時
	if (iodd == 0) {
		patternsum = (iedge * (iedge - 1) / 2);
	}
	//奇数ゼロの時
	else if (iedge == 0) {
		patternsum = (iodd * (iodd - 1) / 2);
	}
	else {
		patternsum = (iodd * (iodd - 1) / 2) + iedge * (iedge - 1) / 2;
	}

	cout << patternsum;

	return 0;
}