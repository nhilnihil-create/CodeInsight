#include <bits/stdc++.h> 
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define pll pair<ll,ll>
#define rep(i,from,to) for(int i=from;i<to;i++)
#define repd(i,from,till) for(int i=from;i>=till;i--)
#define waste ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 1e9+1
#define mod 1e9+7
#define inf1 1e18+1
#define pie 3.14159265358979323846
#define N 100005
using namespace std;

int solve(){
    int n;
    cin>>n;
	set<int> q[n+1];
	rep(i,0,n-1){
		int a,b;
		cin>>a>>b;
		q[a].insert(b);
		q[b].insert(a);
	}
	ll sum=0,ans=0;
	repd(i,n,1){
		auto p=q[i].upper_bound(i);
		if(p==q[i].end()){
		    sum+=n-i+1;
			ans+=sum;
		}
		else{
			sum+=*p-i;
			p++;
			while(p!=q[i].end()){
			    sum=sum-(n-*p+1);
		        p++;
		    }
		ans+=sum;
		}
// 		cout<<i<<" "<<ans<<" "<<sum<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
int main(){
    waste;
    int t;
    //cin>>t;
    t=1;
    while(t--){
       	solve();
    }
}
