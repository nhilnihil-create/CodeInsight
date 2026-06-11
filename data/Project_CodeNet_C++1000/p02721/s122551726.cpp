#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-(a)) : (a))

typedef long long ll;

using namespace std;

int N, K, C;
char input[200000 + 5];
vector<int> left_most;
vector<int> right_most;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	scanf("%d %d %d", &N, &K, &C);
	scanf("%s", input);
	
	int before = -1 -C;

	for (int i = 0; input[i]; ++i)
	{
		if (input[i] == 'o' && i >= before + C + 1)
		{
			before = i;
			left_most.push_back(i);
		}
	}

	before = N + C;

	for (int i = N - 1; i >= 0; --i)
	{
		if (input[i] == 'o' && i <= before - C - 1)
		{
			before = i;
			right_most.push_back(i);
		}
	}

	reverse(right_most.begin(), right_most.end());

	if (left_most.size() == K && right_most.size() == K)
	{
		for (int i = 0; i < K; ++i)
		{
			if (left_most[i] == right_most[i]) printf("%d\n", left_most[i] + 1);
		}
	}

	return 0;
}