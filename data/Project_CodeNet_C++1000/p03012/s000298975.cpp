#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_balance(void) {
	int n;
	int* w;
	cin >> n;
	w = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)cin >> w[i];

	int sum_e = 0, sum_o = 0;
	int min_tmp;
	int min = 100000;

	
		for (int j = 1; j < n; j++) {
			sum_e = 0;
			sum_o = 0;
			for (int k = 0; k < j; k++) sum_e += w[k];
			for (int l = j; l < n; l++) sum_o += w[l];

			min_tmp = abs(sum_e - sum_o);
			if (min > min_tmp) min = min_tmp;
		}
	

	cout << min << endl;
}

int main()
{
    b_balance();

    return 0;
}