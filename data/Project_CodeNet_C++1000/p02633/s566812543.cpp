#include<bits/stdc++.h>

using namespace std; 

typedef long long ll;

typedef long double ld;

#define pb push_back

#define fi first

#define se second

const ll mod = 1e9+7;

const int N = 2e5+5;

void solve(){

	int x; 	cin>>x; 

	cout<<360/__gcd(360,x)<<endl;

}

///  z = 180*(n-2)

/// z/n = 1

/// z = 1*n = 180*(n-2)

///  180*n-1*n = 360

/// n = 360/(180-60)

/// n = 

int main(){

	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int t=1; 

//	cin>>t; 

	while(t--){

		solve();

	}

	return 0;

}