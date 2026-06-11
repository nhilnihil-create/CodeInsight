// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int n;
vector<pair<long long,long long>> points;

inline long long dis(long long x, long long y) {
	return x*x + y*y;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) {
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	long long ans = 0;
	for(int mul1=0;mul1<2;mul1++) {
		for(int mul2=0;mul2<2;mul2++) {
			int m1 = mul1?mul1:-1;
			int m2 = mul2?mul2:-1;
			vector<pair<long long,long long>> p;
			for(int i=0;i<n;i++) p.push_back(make_pair(points[i].first*m1, points[i].second*m2));
			set<pair<long long,long long>> s;
			s.insert(make_pair(0, 0));
			for(int i=0;i<n;i++) {
				vector<pair<long long,long long>> add;
				for(auto &x : s) {
					pair<long long,long long> go;
					go.first = x.first + p[i].first;
					go.second = x.second + p[i].second;
					add.push_back(go);
				}
				for(int i=0;i<add.size();i++) s.insert(add[i]);
				long long mxsofar= -1e18;
				vector<pair<long long, long long>> dl;
				for(auto it=s.rbegin(); it!=s.rend();++it) {
					if(mxsofar >= it->second) {
						dl.push_back(*it);
					}
					else mxsofar = it->second;
				}
				for(auto x : dl) s.erase(x);
			}
			for(auto x : s) ans=max(ans, dis(x.first, x.second));
		}
	}
	cout << fixed << setprecision(50) << sqrt((long double)ans);
	return 0;
}
