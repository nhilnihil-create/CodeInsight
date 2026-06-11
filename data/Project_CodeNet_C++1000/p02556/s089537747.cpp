#include <bits/stdc++.h>
#define Phuong_ ios_base::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a; i<=b; ++i)

/// easy access -------------
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<int, int> pi;
typedef tuple<bool, int, int> tp;
typedef vector<vector<int> > vv;
///-------------------------



int main()
{
    Phuong_; /// <3333
	int n;
	cin >> n;
	vector<pi> a(n);
	for(pi& x:a){
		cin >> x.first >> x.second;
	}	 		
	sort(a.begin(), a.end());
	int minn;
	int ans =0;
	for(int i=0; i<n; ++i){
		if (i==0){
			minn = a[i].first + a[i].second;
		} else {
			ans = max(ans, a[i].first + a[i].second - minn);
			minn = min(minn, a[i].first + a[i].second);
		}
	}
	for(int i=0; i<n; ++i){
		if (i==0){
			minn = a[i].first - a[i].second;
		} else {
			ans = max(ans, a[i].first - a[i].second - minn);
			minn = min(minn, a[i].first - a[i].second);
		}
	}
	cout << ans << '\n';
    return 0;
}
