#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int main() {
    ll n,m,k;cin>>n>>m>>k;
    vector<int> a(n+1),b(m+1);
    ll ans=0,now=0,bnow=m,bsum=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i],bsum+=b[i];
    
    for(int i=0;i<=n;i++) {
    	k-=a[i];
    	if(k<0) break;
    	while(bsum>k) {
    		bsum-=b[bnow];bnow--;
    	}
    	ans=max(ans,i+bnow);
    }
    cout<<ans<<endl;
    return 0;
}