#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
void func()
{
	int64_t N,A,B;
	cin >> N >> A >>B;

	int64_t ans(A);
	if (N % (A + B) < A)
		ans = N % (A + B);

	ans += ((int64_t)(N / (A + B))) * A;
	
	cout << ans << endl;
	
}

int main() {
//	while(1)
	func();
	return 0;
}
