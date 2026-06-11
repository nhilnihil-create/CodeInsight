#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}


int main()
{	
	int N;
	cin >> N;
	vector<string> vec(N);
	rep(i, N) cin >> vec.at(i);

	map<string, int> s_map;

	for (auto elem : vec)
	{
		if (s_map.count(elem) == 0)
		{
			s_map.insert(make_pair(elem, 1));
		}
		else
		{
			s_map[elem]++;
		}
	}

	cout << s_map.size() << endl;

	return 0;
}