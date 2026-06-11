#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define mod (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
int main()
{
	ll n;
	cin>>n;
	vector<PII>a(n);
	for(int i=0;i<n;i++)cin>>a[i].se>>a[i].fi;
	sort(a.begin(),a.end());
	ll cnt = 0;
	for(int i=0;i<n;i++){
		//cout<<cnt<<endl;
		if(cnt+a[i].se > a[i].fi){
			cout<<"No";
			return 0;
		}
		cnt+=a[i].se;
	}
	cout<<"Yes";	
}
