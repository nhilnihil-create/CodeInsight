#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

ll solve(){
	ll n;
	cin>>n;
	if(n&1) return 0;
	ll ans=0;
	n>>=1;
	while(n){
		ans+=(n/5);
		n/=5;
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
