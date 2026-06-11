#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

long long f(long long m) {
	if (m == 0) return 1;
	else return m*f(m - 1);
}




int main()
{
	long long n;
	cin >> n;
	cout << f(n) << endl;
}