#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);


int main()
{
	FIO;
	long long n, k;
	vector<long long>m;
	cin >> n >> k;

	for (long long i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		m.push_back(x);
	}

	sort(m.rbegin(), m.rend());

	long long sum = 0;

	for (long long i = k; i < n; i++)
	{
		sum += m[i];
	}

	cout << sum;
}
