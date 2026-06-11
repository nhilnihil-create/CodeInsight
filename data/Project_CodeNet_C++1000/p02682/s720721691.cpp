#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B, C, K;
	cin >> A >> B >> C >> K;

	int sum = 0;

	if (K <= A) {
		cout << K << endl;
	}
	else if (K <= A + B) {
		cout << A << endl;
	}
	else {
		cout << A - (K - A - B) << endl;
	}

}
