#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define long long long
#define fi first
#define se second
typedef pair<int,int> ii;

vector<ii> vec;
vector<ii> ans;
int pas[100003];

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	int n; scanf("%d", &n);

	if((n&-n) == n)
	{
		printf("No\n");
		return 0;
	}
	vec.push_back({1,1});
	int lar = 0;
	for(int i = 2; i <= n; i++)
	{
		// for(auto it : vec) printf("%d|%d ", it.fi, it.se);
		// 	printf("\n");
		if((i&-i) == i)
		{
			lar = i;
			ans.push_back({i/2, i});

			for(auto &it : vec)
				it.fi ^= i;
			vec.push_back({i,i});
			sort(vec.begin(), vec.end());
		}
		else
		{
			ans.push_back({vec[i-lar].se, i+n});
			ans.push_back({lar, i});
			pas[vec[i-lar].se] = i+n;
			pas[lar] = i;
			vec.push_back({i^lar, i});
		}
	}
	for(int i = 1;  i <= n; i = i+i)
	{
		if(pas[i] <= n)
			ans.push_back({i+n, pas[i]+n});
		else
			ans.push_back({i+n, pas[i]-n});
	}

	printf("Yes\n");
	for(auto i : ans) printf("%d %d\n", i.fi, i.se);
}








