#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
int main()
{
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n)cin>>a[i];
	ll sum = 0;
	rep(i,n) sum += a[i];
	// sum の約数が出来る候補
	set<ll> candidates;
	for(int i = 1; i * i <= sum; i++){
		if(sum % i == 0){
			candidates.insert(i);
			candidates.insert(sum/i);
		}
	}

	ll ans = 1;
	for (ll x:candidates) {
		ll need;
		{	// calc need
			vector<ll> r(n);
			rep(i,n) r[i] = a[i]%x;
			sort(r.begin(),r.end());
			ll B = 0;
			rep(i,n) B += x - r[i];
			ll A = 0; // 区切り位置を左から1個ずつ試す
			need = 1e18;
			rep(i,n){
				A += r[i];
				B -= x-r[i];
				need = min(need, max(A,B));
			}
		}
		if (need <= k) ans = max(ans, x);
	}
	cout << ans << endl;
}
