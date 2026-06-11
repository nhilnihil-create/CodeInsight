#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <iomanip>
#include <unordered_map>
#include <memory.h>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q;

	cin >> n >> q;
	dsu uf(n + 1);
	for (int i = 0; i < q; i++)
	{
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0)
		{
			uf.merge(u, v);
		}
		else
		{
			cout << uf.same(u, v) << '\n';
		}
	}
	return 0;
}