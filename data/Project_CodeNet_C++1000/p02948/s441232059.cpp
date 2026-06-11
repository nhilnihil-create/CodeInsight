#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fo(i,n) for(ll i=0;i<n;i++)
#define fok(i,k,n) for(ll i=k;i<n;i++)
#define ci(x) cin>>x
#define ci2(x,y) cin>>x>>y
#define co(x) cout<<x<<"\n"
#define co2(x,y) cout<<x<<" "<<y<<"\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int INF =1e9;

int main(){
	int n,m;
	ci2(n,m);
	vi profit[m];
	fo(i,n){
		int a,b;
		ci2(a,b);
		if(a>m) continue;
		profit[m-a].pb(b);
	}
	priority_queue<int> pq;
	ll ans=0;
	for(int i=m-1;i>=0;i--){
		if(!profit[i].empty()){
			for(auto c : profit[i]){
				pq.push(c);
			}
		}
		if(!pq.empty()){
			ans+=pq.top();
			pq.pop();
		}
	}
	co(ans);
}
