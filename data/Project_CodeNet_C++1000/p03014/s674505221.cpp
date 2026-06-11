// kyopro.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<map>
#include<algorithm>
#include<set>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
using namespace std;
#define ll long long int
#define rep(N) for(ll i=0;i<N;i++)
#define For(i,N) for(ll i=0;i<N;i++)
ll MOD = 1e9 + 7;
int main()
{
	ll H, W;
	cin >> H >> W;
	vector<string>S(H+2);
	rep(H) {
		cin >> S[i+1];
	}
	rep(H) {
		S[i+1].insert(W, "#");
		S[i+1].insert(0, "#");
	}
	rep(W+2) {
		S[0].push_back('#');
		S[H+1].push_back('#');
	}
	//from
	vector<vector<ll>>NDP(H+2);
	vector<vector<ll>>EDP(H + 2);
	vector<vector<ll>>SDP(H + 2);
	vector<vector<ll>>WDP(H + 2);
	rep(H + 2) {
		NDP[i].resize(W + 2);
		EDP[i].resize(W + 2);
		WDP[i].resize(W + 2);
		SDP[i].resize(W + 2);
	}

	ll ans = 0;

	rep(H+2) {
		For(j, W+2) {
			int flag = 1;
			int flag2 = 1;
			int flag3 = 1;
			if (S[i][j] == '#') {
				NDP[i][j] = -1;
				WDP[i][j] = -1;
				flag = 0;
			}
			if (S[i][W + 1 - j] == '#') {
				EDP[i][W + 1 - j] = -1;
				flag2 = 0;
			}
			if(S[H+1-i][j]=='#'){
				SDP[H+1-i][j] = -1;
				flag3 = 0;
			}
			if(flag!=0) {
				if (i != 0) {
					NDP[i][j] = NDP[i - 1][j]+1;
				}
				else
					NDP[i][j] = 0;
				if (j != 0) {
					WDP[i][j] = WDP[i][j-1]+1;
				}
				else
					WDP[i][j] = 0;

			}
			if (flag3 == 1) {
				if (i != H + 2) {
					SDP[H + 1 - i][j] = SDP[H + 1 - i + 1][j] + 1;
				}
				else
					SDP[H + 1 - i][j] = 0;
			}
			if (flag2 == 1) {
				if (j != W + 1) {
					EDP[i][W + 1 - j] = EDP[i][W + 1 - j + 1] + 1;
				}
				else
					EDP[i][W + 1 - j] = 0;
			}

		}
	}








	rep(H + 2) {
		For(j, W + 2) {
			ans = max(ans, NDP[i][j] + SDP[i][j] + EDP[i][j] + WDP[i][j]+1);
		
		}
	}

	cout << ans<<endl;


}
