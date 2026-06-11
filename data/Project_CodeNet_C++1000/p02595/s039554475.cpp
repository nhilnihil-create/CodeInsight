#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,d;
	cin >> n >> d;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		int x,y; cin >> x >> y;
		if( 1ll * d *  d >= 1ll * x * x + 1ll * y * y) ++cnt;
	}
	cout << cnt << "\n";
	return 0;
}
