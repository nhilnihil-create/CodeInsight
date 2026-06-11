#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(auto x:v) cout<<" "<<x; cout<<endl;
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t=1;
	//cin>>t;
	while(t--){
		int n,k,c;
		cin>>n>>k>>c;
		string s;
		cin>>s;
		vector<int> dp1(n,-1),dp2(n,-1);
		int l=-c-1,tot=0;
		for(int i=0;i<n;i++){
			if(s[i]=='o'&&i>=l+c+1&&tot<k){
				tot++;
				dp1[i]=tot;
				l=i;
			}
		}
		l=n+c,tot=k;
		for(int i=n-1;i>=0;i--){
			if(s[i]=='o'&&i<=l-c-1&&tot>0){
				dp2[i]=tot;
				tot--;
				l=i;
			}
		}
		vector<int>ans;
		for(int i=0;i<n;i++){
			if(s[i]!='x'&&dp1[i]==dp2[i]&&dp1[i]>0)
				ans.pb(i+1);
		}
		if(ans.empty())cout<<endl;
		else{
			for(auto c:ans)cout<<c<<endl;
		}
	}	
}
