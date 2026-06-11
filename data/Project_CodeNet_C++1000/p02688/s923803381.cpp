#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	vector<int> d(n);
	rep(i,k){
		int m;
		cin >> m;
		rep(j,m){
			int a;
			cin >> a;
			d[a-1] = 1;
		}
	}
	int ans = 0;
	rep(i,n)if(d[i] == 0)ans++;
	cout << ans << endl;
	return 0;
}



