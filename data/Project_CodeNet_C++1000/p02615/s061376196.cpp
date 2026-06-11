#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include<set>
#include<map>
using namespace std;

int main()
{
	long long N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	sort(A.rbegin(), A.rend());

	long long sum=0;
	int t = N - 1;
	for (int i = 0; i < A.size(); ++i)
	{
		int lim = 2;
		if (i == 0) lim = 1;
		for (int j = 0; j < lim; ++j)
			if (t > 0)
			{
				sum += A[i];
				--t;
			}
	}
	cout << sum << endl;
}
