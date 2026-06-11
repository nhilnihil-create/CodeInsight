#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int n;
// a[i](1-indexed) を i 番目のモンスターが受けた攻撃量として，d[i+1] = a[i+1] - a[i]
ll d[270000];

void add( int a, int x ){
	for( int i = a; i <= n; i += ( i & -i ) ) d[i] += x;
}

ll kan( int a ){
	ll res = 0;
	for( int i = a; i > 0; i -= ( i & -i ) ) res += d[i];
	return res;
}

// 区間 [l, r] に x を足す
void jia( int l, int r, int x ){
	add( l, x );
	add( r+1, -x );
}

int main(){
	cin >> n;
	ll r, a; cin >> r >> a;
	vector<pair<int, int>> e;
	for( int i = 0; i < n; ++i ){
		int x, y; cin >> x >> y;
		e.emplace_back(x, y);
	}
	sort( e.begin(), e.end() );
	vector<ll> x(n+1);
	vector<ll> h(n+1);
	for( int i = 1; i <= n; ++i ){
		x[i] = e[i-1].first;
		h[i] = e[i-1].second;
	}
	ll ans = 0;
	// 1-indexed なので座標計算するときにベクトル先頭のイテレータを 1 足しておく
	auto xb = x.begin(); ++xb;
	for( int link = 1; link <= n; ++link ){
		//すでに倒している
		if( kan(link) >= h[link] ) continue;
		int recht = upper_bound( x.begin(), x.end(), x[link]+2*r ) - xb;
		ll xuyao = h[link]-kan(link);
		ll cnt = (xuyao+a-1)/a;
		ans += cnt;
		// Fenwick Tree で爆風を実際に起こす
		jia( link, recht, cnt*a );
	}
	cout << ans << endl;
}

/*
方針:
	貪欲に左端のモンスターを倒すことを目標にする
	できるだけ爆風で他のモンスターを巻き込みたい
		→ 左端から +2r のところで爆破する（右端をにぶたんで出す）
	巻き込むモンスター全てに対して実際にダメージ計算をする (Fenwick Tree でゴリ押す)
*/