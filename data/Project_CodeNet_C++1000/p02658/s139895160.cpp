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
	int n;
	cin >> n;
	ll ans = 1;
	bool over = false;
	bool zero = false;
	rep(i,n){
		ll a;
		cin >> a;
		if(a == 0) zero = true;
		// over flow 検出
		if(a > 1e18 / ans){
			over = true;
		} else {
			ans *= a;
		}
	}
	if(zero) cout << 0 << endl;
	else if(over || ans > 1000000000000000000){
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}
