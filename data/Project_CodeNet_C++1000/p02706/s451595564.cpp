#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_homework(void) {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int remain = n - sum;

	if (remain >= 0) cout << remain << endl;
	else             cout << "-1" << endl;
}

int main()
{
    b_homework();

    return 0;
}