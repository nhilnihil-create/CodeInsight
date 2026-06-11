#include<bits/stdc++.h>
using namespace std;

int main(){
	typedef long long ll;
	ll h,n;
	ll no = 0;
	cin >> h >> n;
	for(ll i=0;i<n;i++){
		ll a;
		cin >> a;
		no+=a;
	}
	if(no>=h)cout << "Yes";
	else cout << "No";
}