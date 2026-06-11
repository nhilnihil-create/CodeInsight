// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll gcd(ll a,ll b){ if(b==0) return a;    return gcd(b,a%b);}
ll lcm(ll a,ll b) { return (a/gcd(a,b)*b);}

int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	
	ll x=lcm(c,d);
	ll ans=(b/c-(a-1)/c)+(b/d-(a-1)/d)-(b/x-(a-1)/x);
	cout<<b-a+1-ans<<endl;
}