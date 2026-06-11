#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const ll MOD = 1000000007;

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N){
		cin >> A[i];
	}
	
	ll ans = 1;
	
	map<int,int> mp;
	
	rep(i,N){
		if(A[i] == 0){
			ans *= (3-mp[0]);
			mp[0]++;
			ans %= MOD;
		}else{
			ans *= (mp[A[i]-1]-mp[A[i]]);
			ans %= MOD;
			mp[A[i]]++;
		}
	}
	
	cout << ans << endl;
	
    return 0;
}

