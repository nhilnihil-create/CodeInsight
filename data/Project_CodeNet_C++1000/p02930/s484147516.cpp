#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>

using namespace std;
using ll = long long;


void Students1D()
{
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 1; i < N; ++i)
	{
		int ct = 1;
		int j = i;
		while (j % 2 == 0)
		{
			j /= 2;
			++ct;
		}
		v[i] = ct;
	}
	for (int i = N-1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << v[j+1];
			cout << ' ';
		}
		cout << endl;
	}
}

int main()
{
	Students1D();
	return 0;
}