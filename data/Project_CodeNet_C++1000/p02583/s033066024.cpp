/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>

#define rep(i, n) for(int i = 0; i < n; i++)

//const long long INF = 1LL << 60;
const int INF = 1e9;

int main()
{
	int N = 0;
	std::cin >> N;
	std::vector<int> L(N);
	rep( i, N )	std::cin >> L[i];

	int ans = 0;

	std::sort( L.begin(), L.end() );
	// 100 * 100 * 100なので、全探索して大丈夫 
	for( int a = 0; a < N; a++ )
	{
		for( int b = a+1; b < N; b++ )
		{
			if( L[a] == L[b] )
			{
				continue;
			}

			for( int c = b+1; c < N; c++ )
			{
				if( ( L[a] == L[c] ) || ( L[b] == L[c]) )
				{
					continue;
				}

				int A, B, C;
				A = L[a];
				B = L[b];
				C = L[c];

				if( ( A + B > C ) &&
					( B + C > A ) &&
				    ( C + A > B ) )
				{
					//printf( "[%d, %d, %d]\n", a+1, b+1, c+1 );
					ans++;
				}
			}
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
