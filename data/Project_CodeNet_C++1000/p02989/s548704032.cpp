#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair< int, int > ii;
typedef vector< ii > vii;

void solve(){
	int n; cin>>n;
	vector< int > v(n);
	for(int &i : v) cin >> i;
	if(n&1){
		cout<<1<<endl;
	}else{
		sort(v.begin(), v.end());
		int mid = n >> 1;
		cout<<v[mid] - v[mid - 1]<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

