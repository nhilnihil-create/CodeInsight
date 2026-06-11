#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<vector>
#include<cstring>
#include<stack>
#include<cstdlib>
#include<cmath>

using namespace std;

int main()
{
	long long x;
	cin >> x;
	for (long long a =-100; a <= 1000; a++) {
		for (long long b = a-500; b <= a+500; b++) {
			if ((a * a * a * a * a - b * b * b * b * b) == x) {
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
}

