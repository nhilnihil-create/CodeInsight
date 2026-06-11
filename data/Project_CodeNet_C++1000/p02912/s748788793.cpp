#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
 
int main()
{
	int n, m;	
	cin >> n >> m;	
	priority_queue<ll> p_que;
	rep(i,n){
		ll x;
		cin >> x;
		p_que.push(x);
	}
	while(m--){
		ll now = p_que.top();
		p_que.pop();
		now /= 2;
		p_que.push(now);
	}

	ll ans = 0;
	while(n--){
		ans += p_que.top();
		p_que.pop();
	}
	cout << ans << endl;
}
