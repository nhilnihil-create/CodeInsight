#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mxN=1e5;

int main(){
//#ifndef ONLINE_JUGDE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll x=max(a*c,a*d);
	ll y=max(b*c,b*d);
	cout<<max(x,y);
	return 0;
}

/*
*/


