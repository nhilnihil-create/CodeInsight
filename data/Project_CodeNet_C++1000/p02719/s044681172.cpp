#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n,k;
	cin >> n >> k;
	ll m = n%k;
	ll ans = min(m, abs(k-m));
	cout << ans << endl;  
}