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
	string N;
	cin >> N;
	
	long sum = 0;
	for (int i = 0; i < N.length(); ++i)
	{
		sum += N[i] - '0';
	}

	if(sum%9==0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

}

int main() {
//	while(1)
	func();
	return 0;
}
