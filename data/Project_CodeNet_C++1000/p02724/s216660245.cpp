#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	int x;
	cin >> x;

	int y = x / 500;

	int z = x - 500 * y;

	int cnt = 0;
	while (z > 4) {
		z -= 5;
		cnt++;
	}

		

	cout << y*1000+cnt*5;
}