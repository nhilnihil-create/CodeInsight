#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll mod = 1000000007;

int main(){
	int n, in;
	cin >> n;
	int z = 0;
	vector<int> rgb(3);
	ll ans = 1;
	int f = 0;
	rep(i, n){
		cin >> in;
		int cou = 0;
		int k = -1;
		rep(j, 3) if(rgb[2-j] == in){ cou++; k = 2-j;}
		if(k == -1){ f = 1; break;}
		ans *= cou;
		if(ans >= mod) ans %= mod;
		rgb[k]++;
	}
	if(f == 0){
		cout << ans << endl;
	}else{
		cout << 0 << endl;
	}
	return 0;
}