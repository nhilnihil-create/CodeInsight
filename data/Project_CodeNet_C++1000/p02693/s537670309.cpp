#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	int A, B, K;
	bool flag(false);
	cin >> K;
	cin >> A >>B;

	flag = (A % K == 0 || B % K == 0 || (int)(A / K) != (int)(B / K));

	if (flag)
		cout << "OK\n";
	else
		cout << "NG\n";

}

int main() {

//	while (1)
		func();
	return 0;
}
