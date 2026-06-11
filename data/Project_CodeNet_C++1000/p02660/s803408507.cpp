#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	map<long long, int> m;
	for (long long i = 2; i*i<=N; i+=1)
	{
		while (N%i == 0)
		{
			if (m.count(i) == 0) m.insert(make_pair(i, 1));
			else ++m[i];
			N /= i ;
		}
	}
	if (N != 1 && m.count(N) == 0) m.insert(make_pair(N, 1));

	int cnt = 0;
	for (auto x : m)
	{
		int d = 1;
		while(x.second - d >= 0)
		{
			x.second -= d;
			++d;
			++cnt;
		}
	}
	cout << cnt << endl;
}