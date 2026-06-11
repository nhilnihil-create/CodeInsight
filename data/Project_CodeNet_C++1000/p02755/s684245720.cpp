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
	int A,B;
	cin >> A >>B;

	int minB,maxB;
	minB = B * 10;
	maxB = (B+1) * 10;

	for(int i= minB; i< maxB; i++)
	{
		if ((int)(i * 0.08) == A)
		{
			cout << i << endl;
			return;
		}
	}
	cout << "-1\n";	
}

int main() {
//	while(1)
	func();
	return 0;
}
