#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> d(n+1);

	d.at(0) = 0;
	rep(i, n){
		int t;
		cin >> t;
		d.at(i+1) = d.at(i) + t;
	}

	int ans = 0;
	rep(i, n+1){
		if(d.at(i) <= x)
			ans++;
	}
	cout << ans << endl;
}