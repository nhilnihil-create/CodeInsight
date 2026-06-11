#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define foreach(c,itr) for(__typeof(c)::iterator itr=c.begin();itr!=c.end();itr++)
typedef long long ll;
typedef long double ld;
const ll mod=1000000007;
int i,j;

int main(){
	ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin>>n;
    ll ten=1,nine=1,eight=1;
    rep(i,n){
    	ten=ten*10%mod;
    	nine=nine*9%mod;
    	eight=eight*8%mod;
	}
	ten%=mod; nine%=mod; eight%=mod;
	ll ans=ten-nine*2%mod+eight;
	if(ans<0)ans+=mod;
	cout<<ans<<endl;
	return 0;
}
