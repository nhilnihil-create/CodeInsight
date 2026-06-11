#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_trick_or_treat(void) {
	int n, k;
	cin >> n >> k;
	bool* a;
	int d;
	int l;

	a = (bool*)calloc(n+1, sizeof(bool));
	for (int i = 0; i < k; i++) {
		cin >> d;
		for (int j = 0; j < d; j++) {
			cin >> l;
			a[l] = true;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt = a[i] ? cnt : cnt+1;

	cout << cnt << endl;
}

int main()
{
    b_trick_or_treat();

    return 0;
}
