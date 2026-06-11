#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll a,b,c,k;
	cin >> a >> b >> c >> k;
	ll ans = 0;
	if(k <= a){
	 rep(i,k) ans++;
	 cout << ans << endl;
	 return 0;
	}
	else if(k > a && k <= b){
		rep(i,a) ans++;
		cout << ans << endl;
		return 0;
	}
	else{
		rep(i,a) ans++;
		rep(i,k-b-a) ans--;
		cout << ans << endl;
		return 0;
	}
}