#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define eps 1e-9
#define maxp 101010
#define mod 1000000007
#define pi 3.141592653589793238
#define sin(s) scanf("%lld",&s);
#define sout(s) printf("%lld\n",s);
#define in(s) cin>>s
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c
#define vll vector<ll>
#define out(s) cout<<s
#define outs(s,a) cout<<s<<a
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define gear_change ios_base::sync_with_stdio(false),cin.tie(0)
#define nfl(i,n) for(i=0;i<n;i++)
#define sfl(i,s,e) for(i=s;i<e;i++)
#define ufl(i,n) for(i=n-1;i>=0;i--)
void solve(){
	ll a,b,c;
	in3(a,b,c);
	swap(a,b);
	swap(a,c);
	cout<<a<<" "<<b<<" "<<c<<"\n";
}	
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	clock_t t1=clock();
	gear_change;
	ll test=1;
	// in(test);
	while(test--){
		solve();
	}
	clock_t t2=clock();
	cerr<<"Time elapsed:- "<<(double)(t2-t1)/CLOCKS_PER_SEC<<'\n';
}	