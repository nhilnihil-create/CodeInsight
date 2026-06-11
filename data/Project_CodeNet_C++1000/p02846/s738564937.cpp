#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()

const int INF = 100000002;

int main(){
	vl t(2); rep(i,2) cin >> t[i];
	vl a(2); rep(i,2) cin >> a[i];
	vl b(2); rep(i,2) cin >> b[i];
	vl da(2), db(2);
	a[0] = t[0] * a[0];
	b[0] = t[0] * b[0];
	a[1] = t[1] * a[1] + a[0];
	b[1] = t[1] * b[1] + b[0];
	if(a[1] == b[1]){
		cout << "infinity" << endl;
		return 0;
	}
	
	if(a[1] <  b[1]){
		swap(b[0], a[0]);
		swap(b[1], a[1]);
	}
	ll ans = 0; 
	ll p1 = b[0] - a[0];
 	ll p2 = a[1] - b[1];
	if(p1>0){
		ans  = ceil(p1 / (double) p2) * 2 -1;
		if(p1 % p2 == 0) ans ++;	
	}
	
	cout << ans << endl; 
}
