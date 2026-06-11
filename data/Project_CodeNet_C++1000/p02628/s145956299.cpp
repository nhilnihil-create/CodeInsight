#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void max_self(int &a, int b){ a = max(a, b);}
void min_self(int &a, int b){ a = min(a, b);}

void solve(){
	int n, k; cin>>n>>k;
	vector< int > v(n);
	for(int &i : v) cin>>i;
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0; i<k; i++){
		ans += v[i];
	}
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
