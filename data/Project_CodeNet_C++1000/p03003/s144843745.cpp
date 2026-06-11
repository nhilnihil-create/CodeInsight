#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll N, M;

/*
   dp1[i][j] : S[0..i]とT[0..j] の部分列が一致し、かつS[i]とT[j]を使用する組み合わせの数 
   dp1[-1][-1] = 1 : 部分列が()の場合を表す
   
   acc[i][j] : dp1[-1..i][-1..j]の合計
   
*/
ll dp1[2001][2001];
ll acc[2001][2001];
const ll MOD = 1000000007;

int main(){
	cin >> N >> M;
	
	vector<ll> S(N);
	vector<ll> T(M);
	for ( int i = 0; i < N; i++ )
		cin >> S[i];
	for ( int i = 0; i < M; i++ )
		cin >> T[i];
	
	for ( int i = 0; i < N; i++ ){
		for ( int j = 0; j < M; j++ ){
			dp1[i][j] = 0;
			acc[i][j] = 0;
		}
	}
	
	for ( int i = 0; i < N; i++ ){
		ll asum = 0;
		for ( int j = 0; j < M; j++ ){
			if ( S[i] == T[j] ){
				dp1[i][j] = (i-1<0||j-1<0) ? 1 : acc[i-1][j-1];
			}
			asum = (asum + dp1[i][j])%MOD;
			acc[i][j] = (((i-1<0)?1:acc[i-1][j]) + asum)%MOD;
		}
	}
	
//	for ( int i = 0; i < N; i++ ){
//		for ( int j = 0; j < M; j++ ){
//			cout << dp1[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	
//	for ( int i = 0; i < N; i++ ){
//		for ( int j = 0; j < M; j++ ){
//			cout << acc[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
	
	
	cout << acc[N-1][M-1] << endl;
	
	return 0;
}

