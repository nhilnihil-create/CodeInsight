#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
	cin >> n;
	vector<P> point(n);
	rep(i, n){
		int x, y;
		cin >> x >> y;
		point[i] = P(x, y);
	}
	
	map<P, int> mp;
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			int p = point[i].first - point[j].first;
			int q = point[i].second - point[j].second;
			mp[P(p, q)]++;
			mp[P(-p, -q)]++;
		}
	}
	
	int mx = 0;
	for(auto it_point : mp){
		mx = max(mx, it_point.second);
	}
	
	cout << n - mx << endl;
	return 0;
}

