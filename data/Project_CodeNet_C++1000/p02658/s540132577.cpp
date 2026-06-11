#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a.at(i);
		if(a.at(i) == 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	
	ll max = 1000000000000000000;
	
	ll ans = a.at(0);
	for(int i = 1; i < n; i++){
		if(a.at(i) > max/ans){
			ans = -1;
			break;
		}
		ans *= a.at(i);
	}
	
	cout << ans << endl;
	
}