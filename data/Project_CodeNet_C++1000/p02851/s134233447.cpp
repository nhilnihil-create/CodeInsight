#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;

int main(){
	cin >> N >> K;
	vector<ll> A(N);
	for ( int i = 0; i < N; i++ ){
		ll a;
		cin >> a;
		// 要素の和を K で割った余りが要素の数と等しくなるものの数
		//  == 1を引いた要素の和を K で割った余りが0と等しくなる && 要素数がK未満のものの数
		A[i] = (a-1+K)%K;
	}
	
	//
	vector<pair<ll,ll>> Asum(N+1);
	ll sum = 0;
	for ( int i = 0; i < N; i++ ){
		Asum[i] = {sum,i};
		sum = (sum+A[i])%K;
	}
	Asum[N] = {sum,N};
	
	sort(Asum.begin(), Asum.end(),[](pair<ll,ll> l, pair<ll,ll> r){return (l.first*N*2+l.second)<(r.first*N*2+r.second);});
	
//	for ( int i = 0; i < N+1; i++ )
//		cout << i << " : " << Asum[i].first << "/" << Asum[i].second << endl;
	
	ll count = 0;
	for ( int i = 0; i <= N; ){
		int ct = 1;
		while ( i+ct <= N && Asum[i].first == Asum[i+ct].first ) // 同じfirstが連続する数を数える
			ct++;
		// ここで、 Asum[i] から ct個は firstが同じである
		
		if ( ct >= 2 ){
			// secondの差がK未満の組を数える
			int j = i+1;
			for ( int i0 = i; i0 < i+ct; i0++ ){
				while ( j < i+ct && (Asum[j].second-Asum[i0].second) < K )
					j++;
				// cout << "i0=" << i0 << " " << (j-i0-1) << endl;
				count += (j-i0-1);
			}
			
		}
		i += ct;
	}
	
	cout << count << endl;
	return 0;
}

