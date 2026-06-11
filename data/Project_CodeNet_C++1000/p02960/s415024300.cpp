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


int main(){
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int n = s.size();

  const int DIV = 13, MOD = 1e9+7;
  // dp[i][j]: 1の位から i-1の位までを考慮した時の値を13で割ったあまりがj
  vector<vector<ll>> dp(n+1, vector<ll>(DIV, 0));
  dp[0][0] = 1;
  ll pow10_i = 1;
  for(int i=0; i<n; i++){
      for(int j=0; j<DIV; j++){
          for(int k=0; k<10; k++){
              if(s[i] == '?'){
                int c = (j + k*pow10_i) % DIV;
                dp[i+1][c] = (dp[i+1][c] + dp[i][j])%MOD;
                // cout << " i: " << i << " pow10_i: " << pow10_i << " j: " << j << " k: " << k << " c: " << c << " dp[i][j]: " << dp[i][j] << " dp[i+1][c]: " << dp[i+1][c]  << endl; 
              }
              else{
                k = (s[i]-'0');
                int c = (j + (s[i]-'0')*pow10_i) % DIV;
                dp[i+1][c] = (dp[i+1][c] + dp[i][j])%MOD;
                // cout << " i: " << i << " pow10_i: " << pow10_i <<" j: " << j << " k: " << k << " c: " << c << " dp[i][j]: " << dp[i][j] << " dp[i+1][c]: " << dp[i+1][c]  << endl;
                break;
              }
          }

      }
      pow10_i = ((pow10_i * 10) % MOD) % DIV;//こっちが正解（%MODも入れて良い,意味ないけど)
      //pow10_i = ((pow10_i * 10) % DIV) % MOD;//こっちが正解（%MODも入れて良い,意味ないけど)
      //pow10_i = (pow10_i * 10) % MOD;//こっちだけだとダメ
  }

  // cout << " dp: " << endl; print_vec2(dp);
  cout << dp[n][5] << endl;

}
