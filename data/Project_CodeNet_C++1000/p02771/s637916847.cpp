#include <iostream>
using namespace std;
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	if (A == B || B == C || A == C)
		if (A == B && A == C)
			cout << "No" << "\n";
		else
			cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}