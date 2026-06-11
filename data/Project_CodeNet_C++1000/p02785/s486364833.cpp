#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N,K;
	ll ans=0;
	int i,k;

	cin >> N >> K;

	vector<ll> gv(N);
	rep(i,N) cin >> gv[i];

	sort(gv.begin(),gv.end(),greater<ll>());

	if(N<=K) ans=0;
	else ans=accumulate(gv.begin()+K,gv.end(),0LL);

	cout << ans << endl;

	return 0;
}

