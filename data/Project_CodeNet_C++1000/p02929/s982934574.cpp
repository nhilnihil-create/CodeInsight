#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

/*
0. まずこういうのは基本的に左から見ていくしかない
1. すべて同じ色に揃えたいので，あるセルについて一つ前と異なるならその異なる部分を変える
	（Wide Flip も同じような考え方になる）
2. すべてのセルを選ぶので，各セルに区間の左端か右端かをそれぞれ N 個ずつ定める
3. 各セルが L か R かどうかが決まればどう区間をとっても操作後の結果は変わらない
*/

int main(){
	int n; cin >> n;
	string s; cin >> s;
	ll ans = 1, l = 1, r = 0;
	if( s.front() == 'W' || s.back() == 'W' ) ans *= 0;
	for( int i = 0; i < 2*n-2; ++i ){
		if( s[i] != s[i+1] ) ++l;
		else{
			ans *= l-r;
			ans %= mod;
			++r;
			if( s[i+1] == 'W' ) s[i+1] = 'B';
			else s[i+1] = 'W';
		}
		// cout << l << ' ' << r << endl;
	}
	++r;
	if( l != n || r != n ) ans *= 0;
	for( int k = 1; k <= n; ++k ){
		ans *= k;
		ans %= mod;
	}
	cout << ans << endl;
}