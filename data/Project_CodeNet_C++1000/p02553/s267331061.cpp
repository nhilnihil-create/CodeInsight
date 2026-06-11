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
	ll n1 = a*c;
  	ll n2 = a*d;
  	ll n3 = b*c;
  	ll n4 = b*d;
 
  cout << max(n1, max(n2, max(n3, n4))) << endl;
	
}