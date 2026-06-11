#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << "   ";
		}
		cout << endl;
	}
}


int main(){
	const ll MOD = 998244353;
	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	for(int i=0; i<N; i++){
		cin >> A.at(i);
	}

	const int MAX = 3005;
	vector<vector<ll>> dp(MAX, vector<ll>(MAX, 0));
	//dp[i][j]: Aのi番目までを考慮した時に 和がjにできる個数
	//for(int i=0; i<N; i++) dp[0][i] = 0;
	//ll ans = 0;
	dp[0][0] = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<=S+1; j++){
			dp.at(i+1).at(j) = (dp.at(i+1).at(j) % MOD  +  2*(dp.at(i).at(j) % MOD)) % MOD; //dp[i+1][j] += 2*dp[i][j];//A[i]番目を使わない場合//なぜ2倍なのかよくわからんがとりあえず
			if(j+A[i] <= S) dp.at(i+1).at(j+A.at(i)) = dp.at(i+1).at(j+A.at(i))%MOD  +  dp.at(i).at(j)%MOD;//A[i]を使う場合//dp[i+1][j+A[i]] = dp[i][j] + A[i];
		}
	}
	//print_vec2(dp);
	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<N; j++){
	// 		for(int k=0; k<=S; k++){
	// 			if(k+A.at(j+1) <= S) dp.at(j+1).at(k+A.at(j+1)) = dp.at(j).at(k) + A.at(j+1);
	// 		}

	// 	}

	// 	cout << "i=" << i << " :---------------------------------" << endl;
	// 	print_vec2(dp);

	// 	ans = (ans%MOD + dp[N][S]%MOD) % MOD;//ans += dp[N][S]
	// 	int a_back = A[A.size()-1];
	// 	A.pop_back();//A.erase(A.begin()+A.size()-1);
	// 	A.insert(A.begin()+0, a_back);//一番後ろの要素を一番前へ
	// }

	cout << dp[N][S] << endl;
	
}