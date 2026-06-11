#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_bounding(void) {
	int n, x;
	int* l;
	cin >> n >> x;
	l = (int*)calloc(n + 2, sizeof(int));
	for (int i = 1; i <= n; i++) cin >> l[i];

	int cnt = 1;
	int now = 0;
	for (int i = 2; i <= n + 1; i++) {
		int before = now;
		now = before + l[i - 1];
		if (now <= x) cnt++;
	}

	cout << cnt << endl;
}

int main()
{
    b_bounding();

    return 0;
}