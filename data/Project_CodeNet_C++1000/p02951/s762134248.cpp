#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	int diff1 = A - B;

	if (diff1 >= C) {
		cout << 0 << endl;
	}
	else {
		cout << C - diff1 << endl;
	}
}
