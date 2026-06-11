#include<iostream>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a,b;
	cin >> a >> b;

	ll ans, curr;
	for(ll i=a; i<=b; i++){
		for(ll j=i+1; j<=b; j++){
			curr = ((i%2019)*(j%2019))%2019;
			ans = min(curr, ans);
			if(ans==0){
				cout << 0;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}