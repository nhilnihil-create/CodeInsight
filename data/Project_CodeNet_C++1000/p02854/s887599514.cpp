#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll N;
	cin >> N;
	vector<ll> A(N);
	rep(i,N){
		cin >> A[i];
	}
	ll sum = 0;
	rep(i,N){
		sum += A[i];
	}
	
	rep(i,N-1){
		A[i+1] += A[i];
	}
	
	ll ans = 1LL<<60;
	rep(i,N-1){
		ans = min(ans, abs(sum-2*A[i]));
	}
	
	cout << ans << endl;
    return 0;
}

