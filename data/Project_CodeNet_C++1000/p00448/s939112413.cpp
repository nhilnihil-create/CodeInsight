#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

#define MAX_R 10
#define MAX_C 10000

typedef pair< int, int > P;

int main()
{
	int R, C;
	while( cin >> R >> C, R || C ) {
		bool is_failed[ MAX_R ][ MAX_C ];
		for( int i = 0; i < R; ++i ) {
			for( int j = 0; j < C; ++j ) {
				cin >> is_failed[ i ][ j ];
			}
		}

		int ans = 0;
		for( int k = 0; k < ( 1 << MAX_R ); ++k ) {
			int tmp[ MAX_R ][ MAX_C ];
			// 行をひっくり返す
			for( int i = 0; i < R; ++i ) {
				if( k & ( 1 << i ) ) {
					for( int j = 0; j < C; ++j ) { tmp[ i ][ j ] = !is_failed[ i ][ j ]; }
				} else {
					for( int j = 0; j < C; ++j ) { tmp[ i ][ j ] = is_failed[ i ][ j ]; }
				}
			}
			// 列をひっくり返す
			int cnt = 0;
			for( int j = 0; j < C; ++j ) {
				int cnttmp = 0;
				for( int i = 0; i < R; ++i ) {
					if( !tmp[ i ][ j ] ) { ++cnttmp; }
				}
				cnt += max( cnttmp, R - cnttmp );
			}
			ans = max( ans, cnt );
		}
		cout << ans << endl;
	}
	return 0;
}