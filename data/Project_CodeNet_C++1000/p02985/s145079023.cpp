#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N;long K; cin>>N>>K;
	int a,b; int cnt[N] = {};
	rep(i,0,N-1){
		cin>>a>>b;
		cnt[a-1]++; cnt[b-1]++;
	}
	long fact[K]; fact[1] = 1;
	rep(i,2,K) fact[i] = (fact[i-1] * (K-i)) % mod;
    if(N == 1){ cout<<K<<endl; return 0; }
	long ans = (K * (K - 1)) % mod;
	rep(i,0,N){
		if(K <= cnt[i]) ans = 0;
		else if(1 < cnt[i]) (ans *= fact[cnt[i]]) %= mod;
	}cout<<ans<<endl;
}