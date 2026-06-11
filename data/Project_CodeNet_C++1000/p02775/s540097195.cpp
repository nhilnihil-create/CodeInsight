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

////////////////////////////////////////////////////////////////

ll chmin(ll &a, ll b){ return a = (a<b) ? a : b;}

int main(void) {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());//s[i]がi桁目となるようにする
	ll n = s.size() + 1;
	s += '0';

	const ll MAX = 9 * n + 1;//すべての紙幣を9枚ずつ使う

	//dp[i][j]: (i-1)桁目まで見た時に必要な最小枚数
	//jは i-1桁目で繰り下がりが必要かどうか 1:必要 0:なし
	vector<vector<ll>> dp(n+1, vector<ll>(2, MAX));
	dp[0][0] = 0;
	//dp[0][1] = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<2; j++){
			//i桁目をs[i]にする場合
			int a = s[i] - '0' + j;//(i-1)桁目でa=0としたら，i桁目でaが繰り下がるので，+j(=1)しておく
			int b = 0;
			chmin(dp[i+1][0], dp[i][j] + a + b);

			//i桁目を0にする場合
			a = -j;// a=jじゃなくていいのか？　（よくわからん)
			b = 10 - (s[i] - '0');
			chmin(dp[i+1][1], dp[i][j] + a + b);			
		}

	}
	//cout << " dp: " << endl; print_vec2(dp);
	cout << dp[n][0] << endl;



	
}
