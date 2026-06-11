#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define fill(a,b) memset(a,b,sizeof(a))

#define f first
#define s second
#define pb push_back

#define inf 1e17
#define ninf -1*1e17
#define mod 1000000007
#define N 500005
#define Ns 5005

// string s;
ll n,m,o,z,d,k,l,r;

ll dp[N];
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--){
	    
	    ll ans=0;
	    cin>>n;
	    int x[n],y[n];
	    set<pair<ll,ll>>s;
	    for(int i=0;i<n;i++){
	        int x1,y1;
	        cin>>x1>>y1;
	        s.insert({x1,y1});
	    }
	    ll mi=inf,mi2=inf;
	    for(auto it=s.begin();it!=s.end();it++){
	        
	        if(it==s.begin()){
	            mi=(*it).f+(*it).s;
	            mi2=(*it).f-(*it).s;
	            continue;
	        }
	       // cout<<*it<<" %\n";
	        ll cur=(*it).f+(*it).s;
	        ll cur2=(*it).f-(*it).s;
	        ans=max(ans,cur-mi);
	        ans=max(ans,cur2-mi2);
	        
	        mi=min(mi,cur);
	        mi2=min(mi2,cur2);
	        
	    }
	    cout<<ans;
	}
	    
	return 0;
}
