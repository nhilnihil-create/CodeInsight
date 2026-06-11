#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;

int main(){
	ll a,b,n;
	cin >> a >> b >> n;
	ll m;
	if(n < b){
		m = n;
	}
	else{
		m = b - 1;
	}
	ll ans = m*a/b;
	cout << ans;
	return 0;
}