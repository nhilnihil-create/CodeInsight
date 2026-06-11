#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

// void max_self(int &a, int b){a = max(a, b);}
// void min_self(int &a, int b){a = min(a, b);}

void solve(){
	int n; cin>>n;
	vector< int > v(n), idx(200005);
	for(int &i : v) cin>>i;
	for(int i = 0; i<n; i++){
		if(v[i] == 1){
			idx[v[i]]++;
			continue;
		}
		if(idx[v[i] - 1]){
			idx[v[i]]++;
		}
	}

	for(int i = 200004; i>=1; i--){
		if(idx[i]){
			cout<<n - i<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; //cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
