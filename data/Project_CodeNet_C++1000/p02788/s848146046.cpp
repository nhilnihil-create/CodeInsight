#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
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
typedef tuple<int,int,int> T3;
const int INF = 1000000000;

int main(){
	int n;
	cin >> n;
	ll d,a;
	cin >> d >> a;

	vector<pair<ll,ll>> xh;
	for(int i = 0;i < n;i++){
		ll x,h;
		cin >> x >> h;
		xh.push_back(make_pair(x,h));
	}

	sort(xh.begin(),xh.end());

	ll ans = 0;
	ll now_cnt = 0;
	queue<pair<ll,ll>> g;
	for(int i = 0;i < n;i++){
		ll x = xh[i].first;
		ll h = xh[i].second;
		while(g.size() && g.front().first < x){
			now_cnt -= g.front().second;
			g.pop();
		}
		h -= now_cnt * a;
		if(h > 0){
			g.push(make_pair(x+2*d,(h+a-1)/a));
			now_cnt += (h+a-1)/a;
			ans += (h+a-1) / a;
		}
	}

	cout << ans << endl;
}
