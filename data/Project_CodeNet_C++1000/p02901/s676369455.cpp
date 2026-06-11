#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}
 

ll chmin(ll &a, ll b){ return a = min(a, b);}

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> a(M), b(M);
	vector<int> c(M, 0);// c[i]: i行目のcの2進表記
	for(int i=0; i<M; i++){
		cin >> a[i] >> b[i];
		for(int j=0; j<b[i]; j++){
			int c_tmp; 
			cin >> c_tmp; 
			c_tmp--;
			c[i] += (1<<c_tmp);
		}
	}

	const int INF = 1001001001;
	//dp[s]: 状態sになるために必要な最小コスト
	vector<ll> dp(1<<N, INF);
	dp[0] = 0;// どれも開けない場合は0円ですむ
	for(int i=0; i<M; i++){
		for(int j=0; j<(1<<N); j++){
			int s = j | c[i];
			chmin(dp[s], dp[j]+a[i]);
		}
	}

	int ans = dp.back();
	if(ans == INF) ans = -1;
	cout << ans << endl;

}
