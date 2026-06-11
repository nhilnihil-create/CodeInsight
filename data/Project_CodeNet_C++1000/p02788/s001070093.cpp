#include <iostream>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <string.h>

using namespace std;

// #define for(i,a,b) for (int i=(a);i<(b);++i)
typedef long long ll;
typedef pair<ll,ll> P;
#define REP(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back // vectorに要素追加
#define INF (ll)1e18

ll mod = 1e9+7;

/*
二分探索 binary search
https://qiita.com/drken/items/97e37dd6143e33a64c8c
狭義: ソート済み配列の中から目的のものを高速に探索する
- 単純な線形探索では O(n)の時間がかかる
- 二分探索を行えば O(logn)の時間で済む

めぐる式二分探索
- x = left は条件を満たさない
- x = right は条件を満たす
- left と right の間に条件を満たすようになる境目がある！
-- 境目まではずっと条件を満たしておらず、境目から先はずっと条件を満たしている (単調性)
実装
- left は「常に」条件を満たさない
- right は「常に」条件を満たす
- right - left = 1 になるまで範囲を狭める (最後は right が条件を満たす最小)
*/
ll N,D,A;
vector<ll> a;

// index が条件を満たすかどうか
// 条件: 爆発が届かない
bool isOK(ll index, ll key) {
	if (a[index] >= key) return true;
	else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
	ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	ll right = (ll)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* どんな二分探索でもここの書き方を変えずにできる！ */
	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(mid, key)) right = mid;
		else left = mid;
	}

	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return right;
}

ll ceil(ll A, ll B){
	ll ans = A/B;
	if (A%B!=0)ans++;
	return ans;
}

int main() {
	// 入力
	cin>>N>>D>>A;
	vector<P> XH;
	REP(i,N){
		ll X,H;cin>>X>>H;
		XH.pb(make_pair(X,H)); // (座標, HP)
	}
	
	// 解法
	sort(XH.begin(), XH.end()); // 座標順に並べる
	// 二分探索で iのモンスターを攻撃した時どこjまで攻撃が届くか調べる
	REP(i,N)a.pb(XH[i].first); // 探索を行う配列a
	ll reach[N]; // reach[i]: iを攻撃した時攻撃に巻き込まれない最小のindex
	REP(i,N){
		ll key = XH[i].first + D * 2 + 1; // 爆発が届かなくなる座標
		reach[i] = binary_search(key) ;
	}
	vector<ll> limit[N]; //limit[i]: i番目のモンスターから届かなくなる攻撃のindex
	REP(i,N){
		if (reach[i]<N)limit[reach[i]].pb(i);
	}

	// 貪欲で攻撃回数を計算
	ll ans = 0;
	ll HP[N];
	REP(i,N)HP[i] = XH[i].second;
	ll n_bomb[N];REP(i,N)n_bomb[i] = 0; // 各モンスターに攻撃した回数
	ll n_bomb_reach = 0; // 有効ダメージ
	// REP(i,N)printf("i: %lld, HP: %lld, reach: %lld\n", i, HP[i], reach[i]);
	REP(i,N){// 左から順にモンスターを攻撃
		if (limit[i].size()>0){ // 届かなくなる攻撃がある
			REP(j, limit[i].size()){
				n_bomb_reach -= n_bomb[limit[i][j]] * A; // 届かなくなった攻撃を減算
			}
		}
		if (HP[i]>n_bomb_reach){// モンスターiのHPが残ってるなら
			n_bomb[i] += ceil(HP[i] - n_bomb_reach, A);
			ans += n_bomb[i];
			n_bomb_reach += n_bomb[i] * A;
		}
	}

	//出力
	printf("%lld\n", ans);
}
