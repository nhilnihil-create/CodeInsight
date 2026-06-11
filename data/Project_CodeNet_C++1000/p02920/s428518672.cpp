#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> v(1 << n);
	for (auto& x : v) cin >> x;
	sort(v.rbegin(), v.rend());
	deque<int> q;
	vector<int> cur;
	cur.push_back(v.front());
	for (int i = 1; i < v.size(); i++) q.push_back(v[i]);
	for (int i = 1; i <= n; i++)
	{
		sort(cur.rbegin(), cur.rend());
		stack<int> s;
		for (int j = 0; j < (1 << (i - 1)); j++)
		{
			while (!q.empty())
			{
				int x = q.front();
				q.pop_front();
				if (x < cur[j])
				{
					cur.push_back(x);
					break;
				}
				else
				{
					s.push(x);
				}
			}
		}
		if (cur.size() != (1 << i)) puts("No"), exit(0);
		while (!s.empty())
		{
			q.push_front(s.top());
			s.pop();
		}
	}
	puts("Yes");
	return 0;
}