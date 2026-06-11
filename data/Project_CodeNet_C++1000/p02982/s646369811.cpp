#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_good_distance(void) {
	int n, d;
	int x[20][20] = { 0 };
	cin >> n >> d;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= d; i++) {
			cin >> x[j][i];
		}
	}

	int cnt = 0;

	for (int j = 1; j < n; j++) {
		for (int i = j + 1; i <= n; i++) {
			double sum = 0;
			for (int k = 1; k <= d; k++) {
				int diff = x[j][k] - x[i][k];
				sum += pow(diff, 2.0);
			}
			double root = sqrt(sum);
			int root_int = (int)root;
			if (root - root_int == 0)cnt++;
		}
	}

	cout << cnt << endl;
	
}

int main()
{
    b_good_distance();

    return 0;
}