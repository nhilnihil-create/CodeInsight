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
	vector<ll> a(n+1);
	for(int i = 0;i <= n;i++){
		cin >> a[i];
	}

	vector<ll> v_max(n+1);
	vector<ll> v_min(n+1);
	v_max[n] = a[n];
	v_min[n] = a[n];
	for(int i = n - 1;i >= 0;i--){
		v_min[i] = (v_min[i+1] + 1) / 2 + a[i];
		v_max[i] = v_max[i+1] + a[i];
	}

	if(v_min[0] > 1){
		cout << -1 << endl;
	}
	else{
		ll ans = 0;
		ll v = 1;
		for(int i = 0;i <= n;i++){
			ans += min(v,v_max[i]);
			v = min(v,v_max[i]) - a[i];
			v *= 2;
		}
		cout << ans << endl;
	}
}
