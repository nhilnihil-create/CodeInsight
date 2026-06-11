#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_resistors_in_parallel(void) {
	int n;
	int a;
	cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sum += (1.0 / a);
		//cout << sum << endl;
	}

	cout << (1 / sum) << endl;


}

int main()
{
    b_resistors_in_parallel();

    return 0;
}