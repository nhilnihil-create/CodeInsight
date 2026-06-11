#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef pair<int,int> P;

int main(){
	int N,M;
	cin >> N >> M;
	vector<P> A(N);
	rep(i,N){ int a,b; cin >> a >> b; A[i]=P(b,a); }
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());

	vector<int> sl;
	rep(i,M){ sl.push_back(i+1); }
	ll ans = 0;
	for(P p : A){
		int day = p.second;
		auto itr = lower_bound(sl.begin(),sl.end(),day);
		if(itr==sl.end())continue;
		ans += p.first;
		sl.erase(itr);
	}
	cout << ans << endl;
}
