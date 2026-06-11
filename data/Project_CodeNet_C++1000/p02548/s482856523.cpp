#include <bits/stdc++.h>
using namespace std;
# define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	ll N;
    cin>>N;
    ll ans = 0;
    ll a;
    rep(i,N){
        a = i+1;
        ans += (N-1)/a;
    }
    cout<<ans<<"\n";
	
	return 0;
}