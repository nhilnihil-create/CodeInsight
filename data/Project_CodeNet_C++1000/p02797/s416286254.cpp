#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, k, s;
	cin >> n >> k >> s;
	if(s != 1000000000){
		rep(i, k) cout << s << ' ';
		rep(i, n-k) cout << 1000000000 << ' ';
	}else{
		rep(i, k) cout << s << ' ';
		rep(i, n-k) cout << 999999999 << ' ';
	}
	cout << endl;
	return 0;
}