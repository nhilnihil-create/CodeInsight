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

int main()
{
	int n;
	cin >> n;
	int cnt[300001] = {};
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		a--;
		cnt[a]++;
	}
	sort(cnt, cnt + n);
	int sum[300001] = {};
	// sum[i] = cnt[0] + ... + cnt[i - 1]
	for(int i = 1; i <= n; i++){
		sum[i] = cnt[i - 1] + sum[i - 1];
	}
	for(int k = 1; k <= n; k++){
		int rest = sum[n - k];
		int l = cnt[n - k], r = n / k + 1;
		while(r - l > 1){
			int mid = (l + r) / 2;
			int ind = lower_bound(cnt + n - k, cnt + n, mid) - cnt;
			int need = mid * (ind - n + k) - (sum[ind] - sum[n - k]) ;
			if(need > rest) r = mid;
			else l = mid;
		}
		cout << l << endl;
	}
}
