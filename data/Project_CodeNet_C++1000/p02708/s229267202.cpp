#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

ll solve(){
	ll n,k,ans=0;
	cin>>n>>k;
	while(k<=n+1){
		ans+=(k*(n-k+1)+1);
		ans%=mod;
		k++;
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
