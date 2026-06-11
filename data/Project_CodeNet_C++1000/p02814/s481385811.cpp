#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; ll m;
	cin>>n>>m;
	vector<ll> a(n);
	set<int> st;
	for(auto &x : a){
		cin>>x;
		int cnt = 0;
		while(x%2 == 0){
			x >>= 1;
			cnt++;
		}
		st.insert(cnt);
	}
	if(st.size() > 1){
		cout<<0<<endl;
		exit(0);
	}
	int pw = (*st.begin()); m /= (1<<(pw - 1));
	ll tmp = 1;
	for(auto x : a){
		tmp = tmp*(x/__gcd(x, tmp));
		if(tmp > m)break;
	}
	ll x = (m/tmp);
	x = (x + 1)/2;
	cout<<x<<'\n';

	return 0;
}