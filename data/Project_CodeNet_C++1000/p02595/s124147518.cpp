#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

void max_self(int &a, int b){ a = max(a, b);}
void min_self(int &a, int b){ a = min(a, b);}

void solve(){
	ll n, d; cin>>n>>d;
	int cnt = 0;
	d = d * d;
	for(int i = 0; i<n; i++){
		ll x, y; cin>>x>>y;
		if((x * x + y * y) <= d) cnt++;
	}
	cout<<cnt<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
