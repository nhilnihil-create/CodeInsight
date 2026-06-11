#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_uneven_number(void) {
	
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		string n_str = to_string(i);
		if ((n_str.size() & 0x1) == 0x0) continue;
		cnt++;
	}

	cout << cnt << endl;
}

int main()
{
    b_uneven_number();

    return 0;
}