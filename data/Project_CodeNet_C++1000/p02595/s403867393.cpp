#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	ll  d,x,y;
	int n; cin>>n>>d;
	int ans=0;
	rep(i,n){
		ll x,y; cin>>x>>y;
		if(d*d>=x*x+y*y){
			ans++;
		}
	}
	cout<<ans<<endl;
}