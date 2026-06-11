#include<iostream>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a,b,k;
	cin >> a >> b >> k;

	ll ans1 = max(a-k, 0LL);
	ll ans2 = b;
	if(ans1==0) ans2 = max(b-k+a, 0LL);
	cout << ans1 << " " << ans2;
	return 0;
}