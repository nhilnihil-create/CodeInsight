//============================================================================
// Name        : abc141_f.cpp F - Xor Sum 3
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : https://atcoder.jp/contests/abc141/tasks/abc141_f
//============================================================================

#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

// 参照: https://img.atcoder.jp/abc141/editorial.pdf
int main() {
	int N, i, col;
	cin >> N;

	// 格納
	unsigned long long A[N];
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	// すべての XOR を取る
	// これで 1 になるビットは最大化問題に関わらない
	// ここで 0 になるビットを 1 にできれば大きな数にできるので、0 になるビットを「興味深いビット」と呼ぶことにする
	unsigned long long all_xor = 0LL;
	for (i = 0; i < N; ++i) {
		all_xor ^= A[i];
	}

	// 「興味深いビット」の抽出
	all_xor = ~all_xor; // ~all_xor (「興味深いビット」が立ったもの)
	for (i = 0; i < N; ++i) {
		A[i] &= all_xor;
	}
	all_xor = ~all_xor;

	// 行列 [A0; A1; ...; AN] の行標準形を求める
	int rank = 0;
	for (col = 59; col >= 0; --col) { // 上位ビットから (列方向), 59ビット目～0ビット目
		for (i = rank; i < N; ++i) { // 行方向
			if (A[i] & (1LL << col)) { // col ビット目が立っていたら抜ける
				break;
			}
		}
		if (i == N) { // rank = N と分かった時点で抜ける
			continue;
		}

		if (i > rank) {
			// A[rank] の col ビット目は立っていなかったが、下の行を順に見て行って  A[i] の col ビット目が立っていたなら、
			// A[rank] の col ビット目がここで立つ
			A[rank] ^= A[i];
		}
		// 下のほうの未処理の行
		for (i = rank + 1; i < N; i++) { // 行方向
			A[i] = min(A[i], A[i] ^ A[rank]); // col ビット目は 0 になる
		}

		rank++;
	}

	// 上の行から XOR していく
	unsigned long long x = 0;
	for (i = 0; i < N; i++) {
		x = max(x, x ^ A[i]);
	}

	unsigned long long res = (x << 1) + all_xor;
	cout << res << endl;

	return 0;
}
