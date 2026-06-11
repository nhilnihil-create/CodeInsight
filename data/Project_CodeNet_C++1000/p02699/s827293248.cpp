#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// void max_self(ll &a, ll b){a = max(a, b);}
// void min_self(ll &a, ll b){a = min(a, b);}

void solve(){
	int n, m; cin>>n>>m;
	if(m >= n){
		cout<<"unsafe"<<endl;
	}else{
		cout<<"safe"<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; //cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
