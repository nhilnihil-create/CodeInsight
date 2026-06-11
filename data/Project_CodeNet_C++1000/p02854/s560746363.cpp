#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, in;
	cin >> n;
	ll sum = 0;
	vector<ll> s(n);
	rep(i, n){
		cin >> in;
		sum += in;
		s[i] = sum;
	}
	ll mi = 2000000000000000;
	rep(i, n-1){
		if(mi > abs(s[n-1] - s[i]*2)) mi = abs(s[n-1] - s[i]*2);
	}
	cout << mi << endl;
	return 0;
}