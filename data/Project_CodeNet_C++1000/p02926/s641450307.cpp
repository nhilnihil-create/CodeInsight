#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using ull = unsigned long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vc = vector<char>;
using vvc = vector<vc>;
using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using dd = pair<double, double>;
using vdd = vector<dd>;
using vvdd = vector<vdd>;
using Mii = map<int,int>;
using vMii = vector<Mii>;
using Si = set<int>;
using vSi = vector<Si>;
using vvSi = vector<vSi>;

#define fi first
#define se second
#define INF 1e9 + 5
#define mod(a,m) (a%m+m)%m
#define PB push_back
#define MP make_pair

double ang(ii& a) {
	return atan2(double(a.second), double(a.first));
}

bool comp(ii& a, ii& b) {
	return ang(a) < ang(b);
}

double normsq(ii& a) {
	double x = a.first;
	double y = a.second;
	return x * x + y * y;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(30);
	int n;
	while(cin >> n) {
		vii v(n);
		for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
		sort(v.begin(), v.end(), comp);
		double anssq = 0.0;
		for (int i = 0; i < n; ++i) {
			ii sum = {0,0};
			for (int j = 0; j < n; ++j) {
				sum.first += v[(i+j)%n].first;
				sum.second += v[(i+j)%n].second;
				anssq = max(anssq, normsq(sum));
			}
		}
		double ans = sqrt(anssq);
		cout << ans << '\n';
	}
}

