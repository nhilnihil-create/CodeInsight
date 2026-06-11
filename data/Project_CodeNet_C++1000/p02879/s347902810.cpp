#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{

	int A, B;
	cin >> A >> B;

	if (1 <= A && A <= 9 && 1 <= B && B <= 9) {
		cout << A * B << endl;
	}
	else {
		cout << -1 << endl;
	}
	

	
}
