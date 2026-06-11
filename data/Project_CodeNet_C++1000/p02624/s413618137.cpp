#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	
    ll N;
    cin>>N;
    vector<ll> f(N+1,2);
    f[1]=1;
    ll max_num = (ll)sqrt(N+1);
    ll n;
    ll d;
    rep(i,max_num-1){
        n=i+2;
        if(N/n<n) break;
        rep(j,N/n-1){
            if(n>j+2) continue;
            ++f[n*(j+2)];
            if(j+2!=n) ++f[n*(j+2)];
        }
    }

    ll ans = 0;
    rep(i,N){
        ans += (i+1)*f[i+1]; // 素数の処理
        // cout<<f[i+1]<<"\n";
    }
	cout<<ans<<"\n";
	return 0;
}
