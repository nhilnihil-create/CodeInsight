#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int _w;

int n, a[N];
map<int,int> cnt;

int main() {
	_w = scanf( "%d", &n );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d", a+i );
	for( int i = 1; i <= n; ++i )
		++cnt[a[i]];
	if( cnt.size() == 1 && cnt.begin()->first == 0 ) {
		puts("Yes");
	} else {
		if( n % 3 == 0 ) {
			if( cnt.size() == 3 ) {
				auto it = cnt.begin();
				int x = it->first;
				int xc = it->second;
				++it;
				int y = it->first;
				int yc = it->second;
				++it;
				int z = it->first;
				int zc = it->second;
				if( (x ^ y ^ z) == 0 && xc == yc && xc == zc ) {
					puts("Yes");
				} else {
					puts("No");
				}
			} else if( cnt.size() == 2 ) {
				auto it = cnt.begin();
				int x = it->first;
				int xc = it->second;
				++it;
				int y = it->first;
				int yc = it->second;
				if( x == 0 && yc == xc + xc ) {
					puts("Yes");
				} else {
					puts("No");
				}
			} else {
				puts("No");
			}
		} else {
			puts("No");
		}
	}
	return 0;
}
