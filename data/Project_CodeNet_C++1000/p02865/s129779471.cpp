#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N % 2 == 0) {
		cout << N / 2 - 1 << endl;
	}
	else {
		cout << N / 2 << endl;
	}

}
