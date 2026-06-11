#include<bits/stdc++.h>
using namespace std;
#define ff          first
#define ss          second
#define ll         	long long int
#define pb          push_back
#define ar 			array
#define mp 			make_pair
#define f(i,n)   	for(ll i =0;i<n;i++)
#define inf 		INT_MAX
#define pll 		pair<ll, pair<ll,ll>>
const ll INF = 1e18;
void init(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
}
void solve(){
	
	ll N;
	cin>>N;
	vector<ll> A(N+1 , 0);
	ll sum = 0;
	for(ll i = 0;i<=N;i++){
		cin>>A[i];
		sum += A[i];
	}
	ll ans  = 0;
	ll space  = 1;
	for(ll i = 0;i<=N;i++,space *= 2,space = min(space , sum)){

		ans += min(sum , space);
		
		sum -= A[i];
		space -= A[i];
		if(space < 0){
			cout<<"-1"<<endl;
			return;
		}
	}

	cout<<ans<<endl;
	return;

}
int main(){
	init();
	ll t = 1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
