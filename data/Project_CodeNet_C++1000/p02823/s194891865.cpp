#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin >> n;
	ll a,b;
	cin >> a >> b;

	if((b - a) % 2 == 0){
		cout << (b - a) / 2 << endl;
	}
	else{
		ll ans1 = a + (b - a - 1) / 2;
		ll ans2 = ((n - b) + 1) + (b - a - 1) / 2;
		cout << min(ans1,ans2) << endl;
	}
}
