#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
double condition = 0.0;

void func()
{
	string S;
	cin >> S;
	if (S[2] == S[3] && S[4] == S[5])
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main() {
	//while(1)
	func();
	return 0;
}
