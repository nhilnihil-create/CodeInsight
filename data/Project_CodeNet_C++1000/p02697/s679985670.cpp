#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
void solve(){
	ll n,m;
	cin>>n>>m;
	set<ll> s;
	ll cur=1,d=n-1;
	while(m){
		if((n%2==0&&d==n/2)||s.find(n-d)!=s.end()){
			d--;
			continue;
		}
		cout<<cur<<" "<<cur+d<<"\n";
		cur++;
		s.insert(d);
		d-=2;
		m--;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll qc=1;
    for(ll i=1;i<=qc;i++)
    solve();
}
