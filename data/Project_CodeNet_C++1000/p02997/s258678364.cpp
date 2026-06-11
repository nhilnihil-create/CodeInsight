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

int main()
{
	int n, k;
	cin >> n >> k;
	int mx = (n-1)*(n-2)/2;
	if (mx < k) {
		puts("-1");
		return 0;
	}

	vector<P> ans;
	rep(i,n-1){
		//nを真ん中にする
		ans.push_back({i+1,n});
	}
	int add = mx-k;
	// 辺の候補を列挙しとく
	vector<P> edge;
	rep(i,n-1) rep(j,i) {
		edge.push_back({i+1,j+1});
	}

	rep(i,add) ans.push_back(edge[i]);

	cout << ans.size() << endl;
	rep(i,ans.size()){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}
