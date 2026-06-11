#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n;
	cin >> n;
	vector<ll> ans(n);
	rep(i,n){
		ans[i] = i+1;
	}
	rep(i,n){
		if(ans[i]%3 == 0) ans[i] = 0;
		if(ans[i]%5 == 0) ans[i] = 0;
	}
	ll sum = 0;
	rep(i,n) sum += ans[i];
	cout << sum << endl;
}