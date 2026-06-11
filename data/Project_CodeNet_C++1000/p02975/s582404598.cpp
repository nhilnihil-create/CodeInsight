#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) do{}while(0)
#endif



ll n;



int main(){
	cin >> n;
	map<ll,ll> m;
	
	rep(i,n){
		ll a;
		cin >> a;
		m[a]++;
	}
	
	vector<pll> v;
	for ( auto it : m ){
		v.push_back(it);
	}
	
	bool ok = false;
	if ( v.size() == 1 ){
		if ( v[0].first == 0 )
			ok = true;
	}
	else if ( v.size() == 2 ){
		if ( v[0].first == 0 && v[0].second*2 == v[1].second )
			ok = true;
		if ( v[1].first == 0 && v[1].second*2 == v[0].second )
			ok = true;
	} else if ( v.size() == 3 ){
		if ( v[0].second == v[1].second && v[1].second == v[2].second && (v[0].first^v[1].first) == v[2].first )
			ok = true;
	}
	cout << (ok ? "Yes" : "No") << endl;
	
	
	return 0;
}


