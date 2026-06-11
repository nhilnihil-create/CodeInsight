#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
#define For(i,a,b)  for(int i=a;i<=b;i++)
#define Forr(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define int ll
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define mkp make_pair
#define INF (ll)(1e17)
#define MOD (ll)(998244353)

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	//I won't misunderstand the problem statement anymore.
	int n; cin>>n;
	vector<bool> v;
	For(i,0,n-1){
		int a,b; cin>>a>>b;
		v.eb(a==b);
	}
	For(i,2,n-1){
		if(v[i] && v[i-1] && v[i-2]){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}





















