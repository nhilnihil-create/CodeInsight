#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_81(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i * j == n) {
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
	return ;
}

int main()
{
    b_81();

    return 0;
}