#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A1, A2, A3;
	cin >> A1 >> A2 >> A3;

	int sum = A1 + A2 + A3;

	if (sum >= 22) {
		cout << "bust" << endl;
	}
	else if (sum <= 21) {
		cout << "win" << endl;
	}


}




