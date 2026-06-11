//ポイント：ビットごとに考える、(X(,Y)の選び方に) 依存しないものを探す。
//まずスコア = X + Y = Σ2^i * (Xi + Yi)
//適当にX,Yを選んでXi≠Yi (Xi,Yi={0,1})になったら、他の選び方でもXi≠Yi。このときXi+Yi=1。
//適当にX,Yを選んでXi=Yiになったら、他の選び方でもXi=Yi, このときXi+Yi=2Xi (Xの選び方に依存).
//↑をもうちょっと書きやすい形にすると、全体のxor = Wとおくことで、
//Wi=1なら、常にXi+Yi=1
//Wi=0なら、Xi+Yi=2Xi
//つまり、Wi = 1なるiについては常にスコア += 2^i、合計で += W。
//Wi = 0なるiについてはスコア += 2 * 2^i * Xi。
//ここで、Wj=0なるjについてAiのjビット目を0に置き換えたものをAi'とおく。すると、同じ要素の選び方について、
//Σ2^i * (Xi + Yi) (Wi = 0)は、Aiを使ってもAi'を使っても変化しないので、以降はAi'を用いてみる。
//すると、Wi = 0が常になりたつことになり、スコア = 2Xに変形できる。よって、Xを最大化すればよい。
//今度は、A1'～AN'のうちいくつかを選ぶことで作れるxorの条件（集合）を考える。
//（0個選んでも、全部選んでもxor=0より、そのような場合も考えて良いことに注意する）
//すると、F2上の線形和みたいなので表せる形が条件になることが分かって、線形和（線形従属）といえば掃き出し法なので、
//掃き出し法を実行してみる（(Ai', Aj') -> replace -> (Ai', Ai' xor Aj')してみる）と、作れるxorの集合は変化しない
//ことに気付く。よって、掃き出し法ができ、「自明に貪欲できる形」に変形することができる。

#include <iostream>
#define int long long
#define rep(i, n) for(i = 0; i < n; i++)
#define rrep(i, n) for(i = n - 1; i >= 0; i--)
using namespace std;

int n;
int a[100000];

signed main() {
	int i, j;
	
	cin >> n;
	rep(i, n) cin >> a[i];
	
	int w = 0;
	rep(i, n) w ^= a[i];
	rep(i, n) a[i] &= ~w;
	
	int cor = 0;
	rrep(i, 60) {
		for (j = cor; j < n; j++) {
			 if ((a[j] >> i) & 1) break;
		}
		if (j == n) continue;
		swap(a[cor], a[j]);
		for (j = cor + 1; j < n; j++) {
			if ((a[j] >> i) & 1) a[j] ^= a[cor];
		}
		cor++;
	}
	
	int x = 0;
	rep(i, n) {
		if ((x ^ a[i]) > x) x ^= a[i];
	}
	
	cout << 2 * x + w << endl;
	return 0;
}