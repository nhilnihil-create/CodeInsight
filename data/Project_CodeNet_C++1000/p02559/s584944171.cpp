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
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, q;
	cin >> n >> q;
	fenwick_tree<long long int> tree(n);
	long long int t;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		tree.add(i, t);
	}

	int a, b, c;

	for (int i = 0; i < q; i++)
	{
		cin >> a >> b >> c;
		if (a == 0)
		{
			tree.add(b, c);
		}
		else
		{
			cout << tree.sum(b, c) << '\n';
		}
	}
	return 0;
}