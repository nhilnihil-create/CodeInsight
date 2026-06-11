#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;
	int A, B;
	cin >> A >> B;
	string U;
	cin >> U;


	if (S == U) {
		A -= 1;
	}
	else if (T == U) {
		B -= 1;
	}

	cout << A << " " << B << endl;


}
