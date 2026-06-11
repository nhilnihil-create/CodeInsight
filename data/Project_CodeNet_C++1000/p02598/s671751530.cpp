#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
vector<int> a(200005);
int n, k;

bool f(double x) {
	 if (x == 0) return false;
	 int s=0;
	 rep(i,n) {
		 int know = int(ceil((double)a[i]/x))-1;
		 s += know;
	 }
	 if (s <= k) return true;
	 else return false;
}

int main() {
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	double amax = *max_element(a.begin(),a.end());
	double amin = 0;
	while ((int(ceil(amax))-int(ceil(amin))) >= 1) {
		double amid = (amax + amin)/2;
		if (f(amid)) amax = amid;
		else amin = amid;
	}
	cout << int(ceil(amax)) << endl;
	return 0;
}
