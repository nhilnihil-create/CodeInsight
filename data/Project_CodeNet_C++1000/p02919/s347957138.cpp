#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

ll compute(int ind, set<int> &st){
	auto rit = st.upper_bound(ind);
	auto lit = st.upper_bound(ind); lit--;
	int r1 = *rit; rit++;
	int l1 = *lit;
	if(rit == st.end()){
		lit--; int l2 = *lit;
		return (r1 - ind)*1LL*(l1 - l2);
	}
	if(lit == st.begin()){
		int r2 = *rit;
		return (ind - l1)*1LL*(r2 - r1);
	}
	int r2 = *rit;
	lit--; int l2 = *lit;
	return (r1 - ind)*1LL*(l1 - l2) + (ind - l1)*1LL*(r2 - r1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<int> p(n + 1);
	for(int i = 1; i <= n; i++){
		int x; cin>>x;
		p[x] = i;
	}
	set<int> st;
	st.insert(0);
	st.insert(p[n]);
	st.insert(n + 1);
	ll ans = 0;
	for(int i = n - 1; i >= 1; i--){
		ans += i*compute(p[i], st);
		st.insert(p[i]);
	}
	cout<<ans<<endl;

	return 0;
}