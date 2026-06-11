#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;

int main() {
	speed;
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ans = 0;
	for (int a = 0; a < n; ++a)
		for (int b = a + 1; b < n; ++b)
			for (int c = b + 1; c < n; ++c)
				if (v[a] != v[b] && v[b] != v[c] &&
					v[a] != v[c] && v[a] + v[b] > v[c] && v[c] + v[b] > v[a] && v[a] + v[c] > v[b])
					ans++;
	cout << ans;
}