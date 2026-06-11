
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const long long INF = 1LL << 60;
const int MOD = 1e9 + 7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int N;
	cin >> N;
	std::vector<std::vector<ll>> vecA(N,std::vector<ll>(2));
	rep(i,N){
		cin >> vecA.at(i).at(1);
		vecA.at(i).at(0) = i;
	}


	sort(vecA.begin(),vecA.end(),
		[](const std::vector<ll> &x,const std::vector<ll> &y){
			return x.at(1) > y.at(1);
		});

	//DP table
	std::vector<std::vector<ll>> dp(N+1,std::vector<ll>(N+1));

	ll ans = 0;
	rep(i,N+1){
		rep(j,N+1){

			if(i+j-1 >= N || i+j == 0){
				continue;
			}
			ll active = vecA.at(i+j-1).at(1);
			ll index = vecA.at(i+j-1).at(0);

			dp.at(i).at(j) = max((i>0)?dp.at(i-1).at(j)+active*abs(index-(i-1)):-1,
								(j>0)?dp.at(i).at(j-1)+active*abs(index-(N-1-(j-1))):-1);
			chmax(ans,dp.at(i).at(j));
		}
	}


	cout << ans << endl;
	return 0;

}