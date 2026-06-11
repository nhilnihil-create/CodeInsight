#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
using namespace std;
typedef long long ll;

const ll LMT = pow(10, 9) + 1;

void solver() {
	ll n, k;
	cin >> n >> k;
	
	ll a[n];
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	/**
	 * 長さの範囲の小さい方から見ていってそれが、すべてのaを"合計"k回まで切断で
	 * その短さにできる最小を考える
	 * 
	 * 各aの切断回数はceil(a/l)-1で求まる(l -> チェックする長さ)
	 * （丁度割り切れるパターン、割り切れないパターンの切断面を数える）
	 * 
	 * 1個1個数えると間に合わないので、NG（LEFT)とOK(RIGHT)の中間を見て、
	 * それを新たなOK/NGとする
	 * 次第にTOP-BOTTOM=1に近づいてゆく
	 * この繰り返しの中でTOP<BOTTOMとなることはない
	 */
	// left -> NG, right -> OK
	ll left = 0, right = LMT;
	while (right - left != 1) {
		
		// 自動キャストで小数点以下切り捨てになる？
		ll mid = (left + right) / 2;
		
		// チェック処理
		ll cnt = 0;
		for (ll i = 0; i < n; i++) {
			cnt += (a[i] / mid);
			cnt -= 1;
			if (a[i] % mid != 0) cnt += 1;
		}
		bool isOK = cnt <= k;
		
		if (isOK) right = mid;
		else left = mid;
	}
	cout << right << endl;
}

int main() {
	solver();
	return 0;
}
