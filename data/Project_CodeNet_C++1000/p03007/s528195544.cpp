#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)cin>>a[i];
	SORT(a);
	
	int plus_index = n-1;
	rep(i,n){
		if(a[i] >= 0){
			plus_index = i;
			break;
		}
	}
	plus_index = max(1,plus_index);
	//plus_index以降のものは+にする.ソレより以前は-にする。
	ll now = a[plus_index - 1];
	vector<P> ans(0);
	for(int i = plus_index; i < n -1; i++){
		ans.push_back({now,a[i]});
		now -= a[i];
	}
	// aから残りを引いていく。
	for(int i = 0; i < plus_index - 1; i++){
		ans.push_back({a[n-1],a[i]});
		a[n-1] -= a[i];
	}
	ans.push_back({a[n-1],now});
	a[n-1] -= now;
	cout << a[n-1] << endl;
	for(auto x : ans){
		cout << x.first << " " << x.second << endl;
	}

}
