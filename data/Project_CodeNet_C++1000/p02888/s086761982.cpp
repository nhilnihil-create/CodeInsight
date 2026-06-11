#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const long long INFL = 2e18;
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	vector<int> l(n);
	for(int i = 0;i < n;i++)cin >> l[i];

	sort(l.begin(),l.end());

	ll ans = 0;
	for(int i = 0;i < n-1;i++){
		for(int j = i+1;j < n;j++){
			auto p = lower_bound(l.begin(),l.end(),l[i]+l[j]);
			auto q = upper_bound(l.begin(),l.end(),l[j]-l[i]);
			int cnt = p - q;
			cnt--;//l[j]は必ず選ばれる
			if(l[i] > l[j] - l[i])cnt--;
			ans += cnt;
		}
	}
	cout << ans / 3 << endl;
}
