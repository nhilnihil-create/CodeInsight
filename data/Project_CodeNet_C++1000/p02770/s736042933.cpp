#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;



ll k, q;

int main(){
	cin >> k >> q;
	
	vector<ll> d(k);
	for ( int i = 0; i < k; i++ ){
		cin >> d[i];
	}
	
	/*
		数列 ai は単調非減少、aiの差分の周期はk
		
		for ( qi ){
			数列 d' = Σd%mi  を計算する
			  この数列は1歩でmiの整数倍を2回またぐことはない
			
			result = n - (d%mi=0 となる個数) - (d'がmiをまたぐ回数)
		}
		
	*/
	
	{
		vector<ll> acc(k+1);
		vector<ll> acc0(k+1);
		for ( int i = 0; i < q; i++ ){
			ll n, x, m;
			cin >> n >> x >> m;
			
			ll dsum = 0;
			ll zsum = 0;
			for ( int j = 0; j < k; j++ ){
				acc[j] = dsum;
				acc0[j] = zsum;
				dsum = dsum + d[j]%m;
				zsum = zsum + (d[j]%m==0 ? 1 : 0);
			}
			acc[k] = dsum;
			acc0[k] = zsum;
			
			
			ll repeated = (n-1)/k;
			ll remain = (n-1)%k;
			ll zero_count = repeated*acc0[k] + acc0[remain];
			ll amax = x + repeated*acc[k] + acc[remain];
			
			//cout << endl;
			//cout << "n=" << n << endl;
			//cout << "zero count = " << repeated*acc0[k] << "+" << acc0[remain] << endl;
			//cout << "amax=" << (x+repeated*acc[k]+acc[remain])  << endl;
			
			cout << (n-1) - zero_count - (amax/m - x/m) << endl;
		}
	}
	
	return 0;
}

