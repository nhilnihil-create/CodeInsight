#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_n=2005;
vector<pair<ll,ll> >kids(max_n); 
ll dp[max_n][max_n],n;
ll slove(ll l,ll r){
	if(l>r) return 0;
	if(dp[l][r]) return dp[l][r];
	ll i=n-(r-l+1);
	return 
        dp[l][r]=max(slove(l,r-1)+kids[i].first*(r-kids[i].second),
                    slove(l+1,r)+kids[i].first*(kids[i].second-l)); 
}
int main(){
	scanf("%d",&n);
	for(int i=0,x;i<n;i++){
		scanf("%d",&x);
        kids.push_back({x,i});
    }
	sort(kids.rbegin(),kids.rend());
	slove(0,n-1);
	printf("%lld\n",dp[0][n-1]);
	return 0;
}
