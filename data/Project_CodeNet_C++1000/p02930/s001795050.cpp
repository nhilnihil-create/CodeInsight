#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int ans[501][501] = {};

void solve(int l, int r, int revel)
{
	if(r - l <= 1) return;
	int mid = (l + r) / 2;
	for(int i = l; i < mid; i++){
		for(int j = mid; j < r; j++){
			ans[i][j] = revel;
		}
	}
	solve(l, mid, revel + 1);
	solve(mid, r, revel + 1);
}

int main()
{
	int n;
	cin >> n;
	solve(0, n, 1);
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			cout << ans[i][j];
			if(j == n - 1) cout << endl;
			else cout << " ";
		}
	}
}