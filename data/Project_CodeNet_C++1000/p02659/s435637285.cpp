#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	long long A;
	double B;
	cin >> A >> B;

	long long iB = B*100+0.5;
	long long ans = A * iB /100;
	cout << ans << endl;
}