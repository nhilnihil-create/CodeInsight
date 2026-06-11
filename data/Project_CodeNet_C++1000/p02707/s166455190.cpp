#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

// void max_self(int &a, int b){a = max(a, b);}
// void min_self(int &a, int b){a = min(a, b);}

void solve(){
	int n; cin>>n;
	vector< int > v(n - 1);
	unordered_map< int, int > m;
	for(int &i : v){
		cin>>i;
		m[i]++;
	}
	for(int i = 1; i<=n; i++){
		cout<<m[i]<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
