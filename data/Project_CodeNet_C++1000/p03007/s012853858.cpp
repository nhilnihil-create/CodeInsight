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

using namespace std;

void Diverta2019_2C()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& x : A)
	{
		cin >> x;
	}

	if (N == 2)
	{
		auto x = max(A[0], A[1]);
		auto y = min(A[0], A[1]);
		cout << x - y << endl;
		cout << x << ' ' << y << endl;
		return;
	}

	vector<int> B = A;
	sort(B.begin(), B.end());
	auto pZero = lower_bound(B.cbegin(), B.cend(), 0);
	if (pZero == B.cbegin())
	{
		// B >= 0
		auto sum = accumulate(B.cbegin() + 1, B.cend(), 0);
		sum -= B.front();
		cout << sum << endl;
		auto x0 = B[0];
		auto x1 = B[1];
		for (int i = 2; i < N; ++i)
		{
			auto x2 = B[i];
			cout << x0 << ' ' << x2 << endl;
			x0 -= x2;
		}
		cout << x1 << ' ' << x0 << endl;
		return;
	}
	if (pZero == B.cend())
	{
		// B < 0
		auto sum = accumulate(B.crbegin() + 1, B.crend(), 0);
		sum -= B.back();
		cout << -sum << endl;
		auto x0 = B[N-1];
		for (int i = 1; i < N; ++i)
		{
			auto x1 = B[N - i - 1];
			cout << x0 << ' ' << x1 << endl;
			x0 -= x1;
		}
		return;
	}

	int nm = distance(B.cbegin(), pZero);
	int np = N - nm;

	auto sum = accumulate(B.cbegin() + nm, B.cend(), 0) - accumulate(B.cbegin(), B.cbegin() + nm, 0);
	cout << sum << endl;
	if (np == 1)
	{
		auto x0 = B.back();
		for (int i = 0; i < N - 1; ++i)
		{
			auto x1 = B[i];
			cout << x0 << ' ' << x1 << endl;
			x0 -= x1;
		}
		return;
	}
	auto x0 = B.front();
	for (int i = nm; i < N - 1; ++i)
	{
		auto x1 = B[i];
		cout << x0 << ' ' << x1 << endl;
		x0 -= x1;
	}
	cout << B.back() << ' ' << x0 << endl;
	x0 = B.back() - x0;
	for (int i = 1; i < nm; ++i)
	{
		auto x1 = B[i];
		cout << x0 << ' ' << x1 << endl;
		x0 -= x1;
	}
}

int main()
{
	Diverta2019_2C();
	return 0;
}