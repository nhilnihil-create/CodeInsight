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
	
	int H1,H2,M1,M2,K;
	cin>>H1>>M1>>H2>>M2>>K;
	int time = (H2 - H1) * 60;
	if(H2 < H1){
		time += 24*60;
	}
	
	time += M2 - M1;

	cout<<time - K<<endl;

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
