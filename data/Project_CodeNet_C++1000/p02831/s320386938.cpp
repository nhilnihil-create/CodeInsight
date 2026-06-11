// AUTHOR : Kishan Srivastav
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define in freopen("input.txt", "r", stdin)
#define out freopen("output.txt", "w", stdout)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main() {
	ios
#ifndef ONLINE_JUDGE
	in;
	out;
#endif
	ll a,b;
	cin>>a>>b;
	for(ll i = 1 ; i <= b ; i++){
		if( (a * i ) % b == 0){
			cout<<(a*i)<<endl;
			break;
		}
	}
}