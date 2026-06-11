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
	vector<int> a(n+1);
	rep(i, n+1)cin>>a[i];
	vector<int> b(n);
	rep(i, n)cin>>b[i];

	ll ans = 0;
	rep(i,n){
		// 勇者 i が倒す数
		ll m = min(b[i],a[i]);
		b[i] -= m;
		ans += m;
		m = min(b[i],a[i+1]);
		a[i+1] -= m;
		ans += m;
	}
	cout << ans << endl;
}
