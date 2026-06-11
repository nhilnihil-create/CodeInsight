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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h)cin>>s[i];

	vector<vector<ll>> yoko(h,vector<ll>(w,0));
	vector<vector<ll>> tate(h,vector<ll>(w,0));

	rep(i,h){
		ll count = 0;
		rep(j,w){
			if(s[i][j] == '#') count = 0;
			else {
				count++;
			}
			yoko[i][j] = count;
		}
	}

	rep(j,w){
		ll count = 0;
		rep(i,h){
			if(s[i][j] == '#') count = 0;
			else count ++;
			tate[i][j] = count;
		}
	}
	for(ll i = h - 1; i >= 0; i--){
		for(ll j = w - 2; j >= 0; j--){
			if(s[i][j] == '#') continue;
			yoko[i][j] = max(yoko[i][j],yoko[i][j+1]);
		}
	}
	for(ll j = w - 1; j >= 0; j--){
		for(ll i = h - 2; i >= 0; i--){
			if(s[i][j] == '#') continue;
			tate[i][j] = max(tate[i][j],tate[i+1][j]);
		}
	}

	ll ans = 0;
	rep(i,h){
		rep(j,w){
			chmax(ans, tate[i][j] + yoko[i][j]);
		}
	}
	cout << ans - 1 << endl;
}
