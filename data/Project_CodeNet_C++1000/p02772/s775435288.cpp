#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_papers_please(void) {
	int n;
	cin >> n;
	vector<int> a(n);
	int a_buf;
	string judge = "APPROVED";

	for (int i = 0; i < n; i++) {
		cin >> a_buf;
		if ((a_buf & 0x1) == 0x0) {
			if ((a_buf % 3 != 0)&&(a_buf % 5 != 0)) judge = "DENIED";
		}
	}

	cout << judge << endl;
}

int main()
{
    b_papers_please();

    return 0;
}