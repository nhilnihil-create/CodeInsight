#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_golden_coins(void) {
	int x;

	int max = 0;

	cin >> x;

	max += (int)(x / 500)*1000;

	int remain = x % 500;

	max += (int)(remain / 5) * 5;

	cout << max << endl;
}

int main()
{
    b_golden_coins();

    return 0;
}