#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N, M, V, P;
	cin >> N >> M >> V >> P;

	vector <ll> A(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> A[ii];
	}

	//大きい順にソート
	sort(A.rbegin(), A.rend());
	A.push_back(1e10);	//最後にダミーを追加

	ll borderScore = A[P-1];	//ボーダーのスコア

	//(スコア，人数)のベクタを作成
	vector <pair<ll, ll>> B;
	ll prevScore = A[0];
	ll prevNum = 1;
	for (int ii = 1; ii < A.size(); ++ii){
		if (A[ii] == prevScore){
			prevNum++;
		} else {
			B.push_back(make_pair(prevScore, prevNum));
			prevScore = A[ii];
			prevNum = 1;
		}
	}

	//トップグループ，ボーダーグループの数を計算
	ll topNum = 0;
	ll borderNum = 0;
	ll outOfBorderIdx = 0;
	for (int ii = 0; ii < B.size(); ++ii){
		if (B[ii].first > borderScore){
			topNum += B[ii].second;
		} else if (B[ii].first == borderScore) {
			borderNum += B[ii].second;
		} else {
			outOfBorderIdx = ii;
			break;
		}
	}

	//自分以下のグループに含まれる総数を計算
	vector <ll> lowerNum(B.size());
	ll cnt = 0;
	for (int ii = 0; ii < B.size(); ++ii){
		lowerNum[ii] = N - cnt;
		cnt += B[ii].second;
	}


	ll ans = topNum + borderNum;
	//ボーダーより下の問題が採用されうるかどうか判定
	ll total = 0;
	for (int ii = outOfBorderIdx; ii < B.size(); ++ii){
		ll boxNum = N - (P - 1 + lowerNum[ii]);
		if (boxNum == 0) {
		} else {
			if (ii == outOfBorderIdx){
				ll tmp = topNum + borderNum - (P - 1);
				total += B[ii-1].first * tmp;
			} else {
				total += B[ii-1].first * B[ii-1].second;
			}

			ll cnt = max(0LL, V - (N - boxNum));
			ll tmpTotal = total + cnt * M;
			ll tmpScore = (tmpTotal + boxNum - 1) / boxNum;

			ll refScore = max(borderScore, tmpScore);
			ll score = B[ii].first + M;	//ボーダーより下の問題のスコア

			if (score >= refScore){
				ans = ans + B[ii].second;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
