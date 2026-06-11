#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair< int, int > ii;
typedef vector< ii > vii;

void solve(){
	ll n, m; cin>>n>>m;
	if(n == 1 || m == 1){
		cout<<1<<endl;
		return;
	}	
	cout<<(n * m + 1) / 2<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

