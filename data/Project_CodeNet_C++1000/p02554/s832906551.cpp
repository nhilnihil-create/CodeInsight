#include <iostream>
using namespace std;
typedef long long ll;
const ll mo = 1e9+7;
ll qsm(ll a,ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a % mo; 
		}
		a = a*a % mo;
		b >>= 1;
	}
	return res;
}
int main(){
	ll n;
	cin >> n;
	cout<<((qsm(10ll,n)-2*qsm(9ll,n)+qsm(8ll,n))%mo+mo)%mo<< endl;
	return 0;
}