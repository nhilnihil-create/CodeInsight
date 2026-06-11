// E - Divisible Substring
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(n);++i)
#define modadd(x,y,m) x=(x+(y))%(m)
#define modmul(x,y,m) x=(x*(y))%(m)
#define c2d(c) ((c)-'0') // char to digit

int main(){
	ll N,P; string S; cin>>N>>P>>S;
	ll ans = 0;
	if(P==2 || P==5){
		rep(i, N) if(c2d(S[N-1-i]) % P == 0) ans += N - i;
	}
	else{
		ll ten = 1;
		vector<ll> cnt(P, 0);
		ll r = 0;
		cnt[r]++;
		for(int left=N-1; left>=0; --left){
			modadd(r, c2d(S[left])*ten, P);
			modmul(ten, 10, P);
			cnt[r]++;
		}
		rep(r, P) ans += cnt[r] * (cnt[r]-1) / 2;
	}
	cout<< ans <<endl;
}