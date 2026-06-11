#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int M1,D1;
	cin >> M1 >> D1;
	int M2, D2;
	cin >> M2 >> D2;

	if (M1 + 1 == M2 && D2 == 1) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	
}