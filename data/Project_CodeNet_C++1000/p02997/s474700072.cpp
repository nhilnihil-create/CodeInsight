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
	ll n, k;
	cin >> n >> k;
	// ウニでn+1が行ける
	int now = ((n - 1) * (n - 2) )/ 2;
	if(k > now){
		cout << -1 << endl;
		return 0;
	}
	vector<P> ans(0);
	rep(i,n-1){
		ans.push_back({1,i+2});
	}
	bool end = false;
	For(i,2,n+1){
		For(j,i+1,n+1){
			if(now == k) {
				end = 1;
				break;
			} else {
				ans.push_back({i,j});
				now--;
			}
		}
		if(end)break;
	}
	cout << ans.size() << endl;
	for(auto x:ans){
		cout << x.first << " " << x.second << endl;
	}
}
