#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	rep(i, n) cin >> h.at(i);

	int ans = 0;
	rep(i, n){
		if(k <= h.at(i)) ans++;
	}

	cout << ans << endl;
}