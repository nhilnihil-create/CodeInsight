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
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < k; ++i)
		ans += v[i];
	cout << ans;
}