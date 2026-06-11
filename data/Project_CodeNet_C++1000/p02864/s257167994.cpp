#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int N, K;
vector<ll> H;

ll INF = 1145141919810893;

vector<ll> pressAr;

void press() {
	for (int i = 0; i < H.size(); i++) {
		pressAr.push_back(H[i]);
	}
	sort(pressAr.begin(), pressAr.end());
	pressAr.erase(unique(pressAr.begin(), pressAr.end()), pressAr.end());
	for (int i = 0; i < H.size(); i++) {
		H[i] = lower_bound(pressAr.begin(), pressAr.end(), H[i]) - pressAr.begin();
	}
}

ll dp[300 + 10][300 + 10][300 + 10];

int main() {
	cin >> N >> K;
	H.resize(N + 1);
	for (int i = 0; i < N; i++)cin >> H[i];
	//便宜上0も圧縮配列に入れる。もちろん0なので圧縮されても0番である。
	H[N] = 0;

	press();
	
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
			for (int k = 0; k <= pressAr.size(); k++)
				dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			for (int k = 0; k <= pressAr.size(); k++) {
				if (dp[i][j][k] == INF)continue;
				//塗り替えをする場合
				if (j + 1 <= K) {
					dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k]);
				}
				//塗り替えをしない場合
				if (H[i] <= k) {
					//今見てるのが今までより低いならば、高さを合わせてk -> H[i]に
					dp[i + 1][j][H[i]] = min(dp[i + 1][j][H[i]], dp[i][j][k]);
				}
				else {
					//今見てるのが今までより高いならば、高さをそこに合わせて、ぬるべき回数を増やす
					dp[i + 1][j][H[i]] = min(dp[i + 1][j][H[i]], 
						dp[i][j][k] + (pressAr[H[i]] - pressAr[k]));
				}
			}
		}
	}

	ll ans = INF;
	for (int j = 0; j <= K; j++) {
		for (int k = 0; k <= pressAr.size(); k++) {
			ans = min(ans, dp[N][j][k]);
		}
	}
	cout << ans << endl;
	return 0;
}