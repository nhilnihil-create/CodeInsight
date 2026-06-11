#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	ll n, k;
	cin >> n >> k;
	if(k < n){
		n -= ((n-k)/k+1) * k;
		if(k<n) cout << "error" << endl;
	}
	cout << min(abs(n-k), n) << endl;
}
