#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005;
string s;
ll n,dp[maxn],a[maxn],cnt[maxn],vis[maxn],ans=0,p;
vector<int>v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>p;
	cin>>s;
	int len=n;
	dp[len]=0;
	int res=1;
	if(p==2||p==5) {
		for(int i=0; i<len; i++) {
			if((s[i]-'0')%p==0) {
				ans+=(i+1);
			}
		}
		cout<<ans<<endl;
	} else {
		for(int i=len-1; i>=0; i--) {
			a[i]=(s[i]-'0');
			dp[i]=(dp[i+1]+a[i]*res)%p;
			res=(res*10)%p;
			cnt[dp[i]]++;
		}
		for(int i=0; i<p; i++) {
			ans+=cnt[i]*(cnt[i]-1)/2;
		}
		cout<<ans+cnt[0]<<endl;
	}
	return 0;
}