#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N, A[100000];
vector<int> v[100001];

// 1 ずつ増加する列 3 つに分ける
// 列は空でもよい

ll ans;

signed main(){
	cin >> N;
	rep(i, N){
		cin >> A[i];
		v[A[i]].pb(i);
	}

	if(v[0].size() == 1) ans = 3;
	if(v[0].size() == 2) ans = 6;
	if(v[0].size() == 3) ans = 6;

	int tmp = 3;
	rep(i, N+1){
		if(tmp < v[i].size()){
			cout << 0 << endl;
			return 0;
		}
		tmp = v[i].size();
		int k = 0;
		while(v[i].size() < 3){
			v[i].pb(1000000*(3-k)+i);
			k++;
		}
		sort(v[i].begin(), v[i].end());
	}

	rep(i, N){ // i -> i+1 の場合の数を求める
		for(int j=2; j>=0; j--){
			if(upper_bound(all(v[i+1]), v[i][j]) == v[i+1].end()){
				cout << 0 << endl;
				return 0;
			}
			ll tmp = v[i+1].end() - upper_bound(all(v[i+1]), v[i][j]) - (2-j);
			//cout << tmp << endl;
			ans *= max(tmp, 0LL);
		}
		if(v[i].end()-lower_bound(all(v[i]), 1000000) + 2 == v[i+1].end()-lower_bound(all(v[i+1]), 1000000)) ans /= 2;
		if(v[i].end()-lower_bound(all(v[i]), 1000000) + 3 == v[i+1].end()-lower_bound(all(v[i+1]), 1000000)) ans /= 6;
		ans %= MOD;
	}
	cout << ans << endl;
}