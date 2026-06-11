#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define MOD 1000000007LL

using namespace std;
using llong = long long;


int main()
{
	IOS;

	int n, k;
	set<int> a;
	cin >> n >> k;
	int i, j;
	for (i = 0; i < k; i++)
	{
		int d;
		cin >> d;
		for (j = 0; j < d; j++)
		{
			int tmp;
			cin >> tmp;
			a.insert(tmp);
		}
	}
	cout << n - a.size();


	return 0;
}