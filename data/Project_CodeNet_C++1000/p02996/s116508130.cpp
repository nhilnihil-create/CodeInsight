#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	int n;
	cin >> n;
	vector<pair<ll,ll>> in(n);
	rep(i,n){
		int a,b;
		cin >> a >> b;
		in[i] = make_pair(b,a);
	}
	sort(in.begin(),in.end());
	ll now=0;
	bool can = true;
	rep(i,n){
		now+=in[i].second;
		if(in[i].first<now)
			can = false;
	}
	if(can) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
