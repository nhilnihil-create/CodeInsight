#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	LL H;cin >> H;
	LL tmp = 0;
	while(H!=1){
		H /= 2;
		tmp++;
	}
	LL ans = 0;
	LL res;
	for(LL i = 1;i <= tmp; i++){
		res = 1;
		rep(j,i){
			res *= 2;
		}
		ans += res;
	
	}
	ans += 1;
	cout << ans << endl;
}











