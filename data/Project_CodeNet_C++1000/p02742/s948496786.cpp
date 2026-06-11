#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;

int main(){
	LL H,W;cin >> H >> W;
	LL ans = 0;
	LL tmp;
	if(H == 1||W == 1){
		cout << 1 << endl;
		return 0;
	}
	tmp = H/2;
	ans += tmp * W;
	if(H%2==1){
	tmp = (W+1)/2;
	ans += tmp;
	}
	cout << ans << endl;
}








