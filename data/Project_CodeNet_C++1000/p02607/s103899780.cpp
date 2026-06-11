#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ii pair < int, int >
#define iii pair < int, ii >
#define INF 987654321
#define LINF 987654321987654321

int arr[105];

int main()
{
	cio;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1 && arr[i] % 2 == 1)
			ans++;
	}

	cout << ans;
}