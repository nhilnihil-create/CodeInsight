#include <iostream>

using namespace std;

int main()
{
	string N;
	int S = 0;
	cin >> N;
	/*
	N = "123456789";
	N = "123";
	*/

	for (int i = 0; i < N.size(); i++)
		S += N[i] - '0';
	cout << ((S % 9 != 0) ? "No" : "Yes") << endl;

	return (0);
}
