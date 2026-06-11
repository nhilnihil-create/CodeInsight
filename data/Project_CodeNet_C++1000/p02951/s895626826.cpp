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

	int n = A - B;

	if (C - n > 0) {
		cout << C - n << endl;
	}
	else {
		cout << 0 << endl;
	}

}




