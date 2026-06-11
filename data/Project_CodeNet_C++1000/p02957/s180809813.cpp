#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b;
	cin >> a >> b;
	int mx,mn;
	if(a > b){
		mx = a;
		mn = b;
	}
	else if (a < b){
		mx = b;
		mn = a;
	}
	bool ok = false;
	int ans = 0;
	for(int i = mn; i <= mx; i++){
		if(abs(a-i) == abs(b-i)){
			 ok = true;
			 ans = i;
			}
	}
	if(ok) cout << ans << endl;
	else cout << "IMPOSSIBLE" << endl;
}


// cout << fixed << setprecision(15) <<  << endl;