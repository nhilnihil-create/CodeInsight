#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void b_one_clue(void) {
	int k, x;
	cin >> k >> x;

	int start = x - k + 1;
	int end = x + k - 1;

	for (int i = start; i <= end; i++) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
    b_one_clue();

    return 0;
}