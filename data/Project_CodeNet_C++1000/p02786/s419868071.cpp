#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (ll i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int i,k;
	ll H;
	ll ans=0;
	ll ctr=0;

	cin >> H;

	while(H>1){
		H/=2;
		ctr++;
	}
	
	rep(i,ctr+1) ans+=pow(2.0,i);

	cout << ans << endl;

	return 0;
}

