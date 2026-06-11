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
int ans[N];
map<int, int> mc;
vector<pair<int, int>> v;
void add(vector<pair<int, int>>& vp, int a, int b)
{
	if (!vp.empty() && vp.back().first == a) vp.back().second += b;
	else vp.emplace_back(a, b);
}
void solve(int key)
{
	if (ans[key] != -1) return;
	auto pq = v;
	int& res = ans[key] = 0;
	while (!pq.empty())
	{
		int sum = 0;
		vector<pair<int, int>> vp;
		while (!pq.empty() && sum < key)
		{
			sum += pq.back().second;
			vp.push_back(pq.back());
			pq.pop_back();
		}
		if (sum < key) break;
		if (vp.size() == 1)
		{
			int a, b;
			tie(a, b) = vp.back();
			res += b / key;
			if (a > 1 && b >= key)
				add(pq, a - 1, b / key * key);
			if (b % key)
				add(pq, a, b % key);
			continue;
		}
		res++;
		int cur = key;
		for (auto& p : vp)
		{
			int a, b;
			tie(a, b) = p;
			int o = min(cur, b);
			cur -= o;
			if (b - o > 0)
			{
				if(a > 1) add(pq, a - 1, o);
				add(pq, a, b - o);
				p.second = 0;
			}
		}
		reverse(vp.begin(), vp.end());
		for (auto& p : vp)
		{
			if (p.second == 0) continue;
			if (p.first > 1) add(pq, p.first - 1, p.second);
		}
	}
	if (res == 0)
	{
		for (int i = key + 1; i < N; i++)
		{
			if (ans[i] == 0) break;
			ans[i] = 0;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mm;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		mm[x]++;
	}
	for (auto& p : mm)
	{
		mc[p.second]++;
	}
	for (auto& p : mc)
		v.push_back(p);
	MEM(ans, -1);
	ans[1] = n;
	for (int i = 2; i <= n; i++)
	{
		solve(i);
		int l = i, r = n;
		int key = l;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			solve(mid);
			if (ans[mid] == ans[i]) key = mid, l = mid + 1;
			else r = mid - 1;
		}
		for (int j = i; j <= key; j++) ans[j] = ans[i];
		i = key;
	}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}