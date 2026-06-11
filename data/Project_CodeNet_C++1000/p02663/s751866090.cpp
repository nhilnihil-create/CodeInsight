#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector< int > v, ans(10004, -1);

void solve(){
	int h, m, a, b, k;
	cin>>h>>m>>a>>b>>k;
	cout<<((a * 60) + b - (h * 60) - m - k)<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
