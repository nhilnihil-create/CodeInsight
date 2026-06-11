#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


/*
  dp[k][m]
    鍵 0-k までを使用して、パターンmを開ける場合に dp[k+1][m] 円必要

*/

ll N, M;
int dp[1001][1<<12];

int patterns[1<<12];
int pattern_count;
// mask & x == x となる全てのxをpatternsに入れる
void get_patterns( int mask ){
	pattern_count = 0;
	for ( int i = 0; i < mask; i++ ){
		if ( (mask & i) == i )
			patterns[pattern_count++] = i;
	}
}


int main(){
	cin >> N >> M;
	int N2 = (1<<N);
	
	vector<int> a(M);
	vector<int> m(M);
	for ( int i = 0; i < M; i++ ){
		int b;
		cin >> a[i] >> b;
		for ( int j = 0; j < b; j++ ){
			int c;
			cin >> c;
			m[i] |= (1<<(c-1));
		}
	}
	
	const int BIG = 200000000;
	for ( int k = 0; k <= M; k++ )
		for ( int p = 0; p < N2; p++ )
			dp[k][p] = (p==0) ? 0 : BIG;
	
	
	for ( int k = 0; k < M; k++ ){
		int ak = a[k];
		int mk = m[k];
		get_patterns(mk);
		
		for ( int p = 0; p < N2; p++ ){
			if ( (p & mk) == mk ){ // 鍵kを使う場合
				int d = dp[k][p];
				for ( int i = 0; i < pattern_count; i++ ){
					d = min( d, ak+dp[k][(p&~mk)|patterns[i]] );
				}
				dp[k+1][p] = d;
			}
			else {
				dp[k+1][p] = dp[k][p];
			}
		}
		
		//for ( int p = 0; p < N2; p++ )
		//	cout << (dp[k+1][p] == BIG ? -1 : dp[k+1][p]) << " ";
		//cout << endl;
	}
	
	
	
	cout << (dp[M][N2-1] == BIG ? -1 : dp[M][N2-1]) << endl;
	
	return 0;
}

