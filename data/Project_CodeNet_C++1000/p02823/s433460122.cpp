#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	ll n, a, b;
	cin >> n >> a >> b;
	ll k = abs(a-b);
	if(k%2 == 0){
		cout << k/2 << endl;
	}else{
//		ll ans0 = min(b-1, n-a); 
		ll ans0 = (n-b+1+n-a)/2;
		ll ans1 = (a-1+1+b-1)/2;
		cout << min(ans0, ans1) << endl;
	}
	return 0;
}