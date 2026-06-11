

#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
#define PI acos(-1)

int main()
{
	long long A;
	string B;

	cin >> A >> B;

	long long C = (B[0] - '0') * 100 + (B[2] - '0') * 10 + (B[3] - '0');
	cout << A * C / 100 << endl;
	

}

