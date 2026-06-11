#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	
    ll N;
    cin>>N;
    vector<ll> f(N+1,1);
    f[1]=1;
    ll max_num = (ll)sqrt(N+1);
    ll n;
    ll d;
    rep(i,N-2){
        n=i+2;
        if(f[n]!=1) continue;
        d = 1;
        while(n<=N){
            rep(j,N/n){
                f[n*(j+1)] = f[n*(j+1)]/d*(d+1);
            }
            n*=(i+2);
            ++d;
        }
    }

    
    ll ans = 1;
    rep(i,N-1){
        ans += (i+2)*max((ll)2,f[i+2]); // 素数の処理
        // cout<<f[i+2]<<"\n";
    }
	cout<<ans<<"\n";
	return 0;
}
