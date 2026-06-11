#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> l(n);
	rep(i, n) cin >> l.at(i);
	
	vector<int> d(n+1);
	d.at(0) = 0;
	for(int i = 1; i <= n; i++){
		d.at(i) = d.at(i-1) + l.at(i-1);
	}

	int ans = 0;
	rep(i, n+1) if(d.at(i) <= x) ans++;

	cout << ans << endl;
}