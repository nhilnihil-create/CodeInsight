#include<iostream>
#include<vector>
#include<algorithm>
using ll = long long;
using namespace std;

int main(){
	ll n,a,b;
	cin >> n >> a >> b;
	ll d = n / (a + b);
	ll ans = 0;
	ans += a * d;
	ll r = n % (a + b);
	if(r > a){
		ans += a;
	}else{
		ans += r;
	}
	cout << ans << endl;
	return 0;
}
