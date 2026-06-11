#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	ll n, d, a;
	cin >> n >> d >> a;
	vector<pair<ll, ll> > xh(n);
	for (int i = 0; i < n; i++){
		cin >> xh[i].first >> xh[i].second;
	}
	sort(xh.begin(), xh.end());

	ll sum = 0, ans = 0;
	queue<pair<ll, ll> > que;
	for (int i = 0; i < n; i++){
		if (xh[i].second > sum){
			ll num = (xh[i].second - sum + a - 1)/a;
			ans += num;
			sum += num*a;
			que.push(make_pair(xh[i].first + 2*d, num*a));
		}
		if (i != n-1){
			while (!que.empty() && que.front().first < xh[i+1].first){
				sum -= que.front().second;
				que.pop();
			}
		}
	}
	cout << ans << endl;
	return 0;
}
