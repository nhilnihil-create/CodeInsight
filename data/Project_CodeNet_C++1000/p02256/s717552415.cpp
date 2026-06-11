#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int large, int small)
{
    if (small == 0) return large;
	else if (large < small) gcd(large, small%large);
	else gcd(small, large%small);
}

int main()
{
	int A[2], small, large;
	int result;
	
	for(int i = 0; i < 2; i++) cin >> A[i];
	
    result = gcd(A[0], A[1]);
	
	cout << result << endl;
	
	return 0;
}