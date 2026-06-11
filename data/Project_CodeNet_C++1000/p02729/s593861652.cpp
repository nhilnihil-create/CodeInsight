#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
	// violinista forever xd
	ios::sync_with_stdio(0),cin.tie(0);
	
	ll n,m;
	cin>>n>>m;
	ll rta=0;
	rta+=n*(n-1)/2;
    rta+=m*(m-1)/2;
    cout<<rta<<endl;
	
	return 0;
}