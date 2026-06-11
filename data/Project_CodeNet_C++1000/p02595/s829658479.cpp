#include<bits/stdc++.h>
#define ll long long
#define f first
#define  s second
#define pii pair<int,int>
#define pll pair<ll,l>
#define ull unsigned ll
#define mp make_pair
#define pb push_back

using namespace std;


int main(){
	int n;cin>>n;
	ll d;cin>>d;
	int ans=0;
	for(int i=1;i<=n;i++){
		ll x,y;cin>>x>>y;
		if(x*x+y*y<=d*d)ans++;
	}
	cout<<ans;
	return 0;
}
