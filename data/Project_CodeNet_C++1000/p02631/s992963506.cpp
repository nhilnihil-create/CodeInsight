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

ll arr[200005];

int main()
{
	cio;
	ll n;
	cin >> n;

	ll x = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		x = x ^ arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		cout << (x ^ arr[i]) << ' ';
	}
}