#include<bits/stdc++.h>
#define sonic ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define fi first
#define se second
#define pb push_back
using namespace std;

const ll INF=1e18;
const int N=1e5+17;

void solve(){
	ll x,y,a,b;
	cin>>x>>y>>a>>b;
	cout<<max(max(x*a,x*b),max(y*a,y*b));
}

int main(){
	sonic
	int TEST=1;
	//cin>>TEST;
	while(TEST--){
		solve();
		cout<<'\n';
	}
}
