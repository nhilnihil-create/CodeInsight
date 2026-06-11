#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
 
#define sec second
#define fir first
#define mo 1000000007
#define inf 1e18
#define rep(i, s, n) for (ll i = s; i < n; i = i + 1)
#define rrep(i,s,n) for(ll i=s;i>=n;i--)

ll mod(ll n) { return (n % (ll)mo + (ll)mo)%(ll)mo;}
int main(){
	ll l,r;
	cin>>l>>r;
	ll d;
	cin>>d;
	ll cnt = 0;
	rep(i,l,r+1){
		if(i%d==0) ++cnt;
	}
	cout<<cnt;
}
		 