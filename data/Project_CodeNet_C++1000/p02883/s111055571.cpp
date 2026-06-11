//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

ll	n , k;
vector<int> a(1000001),f(1000001);

// 二分探索法
// index が条件を満たすかどうか
bool isOK(ll index) {
	ll  c = 0;
	for(int i=0;i<n;i++) {
		if ((ll)a[i]*f[i] > index) c += a[i] - index / f[i];
	}
	if (c > k) return false;
    else return true;
}
// 汎用的な二分探索のテンプレ
ll binary_search() {
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right = 1000000000001; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        ll mid = right + (left - right) / 2;

        if (isOK(mid)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

int main() {
	ll		b,c,d,w,h,i,j,l,m,x,y,z;
	ll		ans = 0;
	string	s;
	cin >> n >> k;
	for(i=0;i<n;i++) cin >> a[i];
	for(i=0;i<n;i++) cin >> f[i];

	auto itra = a.begin();
	auto itrf = f.begin();
	sort(itra , itra + n);
	sort(itrf , itrf + n);
	reverse(itra , itra + n);

	ans = binary_search();
	cout << ans << endl;
	return 0;
}
