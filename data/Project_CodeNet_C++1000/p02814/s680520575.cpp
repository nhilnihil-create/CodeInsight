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
	set<int> st;
	ll lcm = 1;
	for(int i = 0; i < n; i++){
		ll x; cin>>x;
		int cnt = 0;
		while(x%2 == 0){
			x >>= 1;
			cnt++;
		}
		cnt--;
		st.insert(1<<cnt);
		lcm = lcm*(x/__gcd(x, lcm));
		if(lcm > m){
			cout<<0<<endl;
			exit(0);
		}
	}
	if(st.size() != 1){
		cout<<0<<endl;
		exit(0);
	}
	m /= (*st.begin());
	ll mul = m/lcm;
	cout<<(mul + 1)/2<<endl;

	return 0;
}