#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int N;
	cin >> N;

	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		double a;
		cin >> a;
		sum += 1.0 / a;
	}
	cout << 1.0 / sum << endl;
}
