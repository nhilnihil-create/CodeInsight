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
	int a,b,c;
	cin>>a>>b>>c;
	int k;
	cin>>k;
	int count = 0;
	while( a >= b ){
		count++;
		b *= 2;
	}
	while( b >= c){
		count++;
		c *= 2;
	}
	if(count <= k)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}