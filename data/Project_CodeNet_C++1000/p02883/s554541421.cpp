#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



ll N, K;
vector<ll> A, F;

int main(){
	cin >> N >> K;
	
	A.resize(N);
	F.resize(N);
	for ( int i = 0; i < N; i++ ){
		cin >> A[i];
	}
	for ( int i = 0; i < N; i++ ){
		cin >> F[i];
	}
	
	sort(A.begin(),A.end());
	sort(F.begin(),F.end(),[](const ll& l, const ll& r){return l > r;});
	
	ll tmax = 0;
	for ( int i = 0; i < N; i++ )
		tmax = max( tmax, A[i]*F[i] );
	ll tmin = -1;
	
	// 二分探索
	// tmin: K回の修行で達成できない成績 の最大値
	// tmax: K回の修行で達成できる成績 の最小値
	while ( tmax-tmin > 1 ){
		ll t = tmin + (tmax-tmin)/2;
		ll k = 0; // 成績tを達成するために必要な修行回数
		for ( int i = 0; i < N; i++ ){
			ll a = t / F[i];
			if ( A[i] > a )
				k += A[i]-a;
		}
		
		if ( k <= K )
			tmax = t;
		else
			tmin = t;
	}
	
	cout << tmax << endl;
	
	return 0;
}

