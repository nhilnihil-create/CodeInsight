#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N = 200010;
int _w;

int n, a, b, c, d;
char s[N];
vector<pii> stone, interval;

void solve_stone() {
	for( int i = 1; i <= n; ++i )
		if( s[i] == '#' ) {
			int j;
			for( j = i; j <= n && s[j] == '#'; ++j );
			--j;
			if( j-i+1 >= 2 ) {
				stone.push_back( pii(i, j) );
			}
			i = j;
		}
}

void solve_interval() {
	stone.push_back( pii(0, 0) );
	stone.push_back( pii(n+1, n+1) );
	sort(stone.begin(), stone.end());
	for( int i = 1; i < (int)stone.size(); ++i ) {
		int L = stone[i-1].second + 1;
		int R = stone[i].first - 1;
		if( L <= R )
			interval.push_back( pii(L, R) );
	}
}

int main() {
	_w = scanf( "%d%d%d%d%d", &n, &a, &b, &c, &d );
	_w = scanf( "%s", s+1 );
	solve_stone();
	solve_interval();
	if( c > d ) {
		pii now(-1, -1);
		for( pii inter : interval ) {
			if( a >= inter.first && c <= inter.second )
				now = inter;
		}
		if( now == pii(-1, -1) ) {
			puts("No");
		} else {
			bool flag = false;
			for( int i = b; i <= d; ++i )
				if( s[i] == '.' && s[i-1] == '.' && s[i+1] == '.' )
					flag = true;
			puts( flag ? "Yes" : "No" );
		}
	} else {
		bool flag1 = false, flag2 = false;
		for( pii inter : interval ) {
			if( a >= inter.first && c <= inter.second )
				flag1 = true;
			if( b >= inter.first && d <= inter.second )
				flag2 = true;
		}
		if( flag1 && flag2 ) puts("Yes");
		else puts("No");
	}
	return 0;
}
