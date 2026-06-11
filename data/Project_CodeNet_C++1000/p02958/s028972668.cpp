#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_0or1_swap(void) {
	int n;
	int* p;
	int* p_copy;
	int d;
	cin >> n;
	p = (int*)calloc(n, sizeof(int));
	p_copy = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		cin >> d;
		p[i] =d;
		p_copy[i] = d;
	}

	sort(p_copy, p_copy + n);

	int det = 0;
	for (int i = 0; i < n; i++) {
		int diff = p[i] - p_copy[i];
		if (diff != 0) det++;
	}

	if (det > 2)cout << "NO" << endl;
	else        cout << "YES" << endl;
}

int main()
{
    b_0or1_swap();

    return 0;
}