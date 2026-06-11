#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	int K;
	string S;
	cin >> K;
	cin >> S;

	if (S.length() <= K)
		cout << S << endl;
	else
		cout << S.substr(0, K) << "..." << endl;
	return;
}

int main() {

//while (1)
		func();
	return 0;
}
