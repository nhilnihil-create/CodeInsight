#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int H, W, A, B;
	cin >> H >> W >> A >> B;

	vector<vector<int>> mat(H, vector <int> (W, 0));

	if ( (A==0) && (B==0) ){
		//何もしない
	} else if (A==0) {
		for (int ii = 0; ii < B; ++ii){
			for (int jj = 0; jj < W; ++jj){
				mat[ii][jj] = 1;
			}
		}
	} else if (B==0) {
		for (int ii = 0; ii < H; ++ii){
			for (int jj = 0; jj < A; ++jj){
				mat[ii][jj] = 1;
			}
		}
	} else {
		int offset = 0;
		for (int ii = 0; ii < H; ++ii){
			for (int jj = 0; jj < A; ++jj){
				int idx = (jj + offset) % W;
				mat[ii][idx] = 1;
			}
			offset = (offset + A) % W;
		}
	}

	bool OK = true;
	//行のチェック
	for (int ii = 0; ii < H; ++ii){
		int cntZero = 0;
		int cntOne = 0;
		for (int jj = 0; jj < W; ++jj){
			if (mat[ii][jj] == 0){
				cntZero++;
			} else {
				cntOne++;
			}
		}
		int num = min(cntOne, cntZero);
		if (num != A){
			OK = false;
			break;
		}
	}
	//列のチェック
	if (OK){
		for (int jj = 0; jj < W; ++jj){
			int cntZero = 0;
			int cntOne = 0;
			for (int ii = 0; ii < H; ++ii){
				if (mat[ii][jj] == 0){
					cntZero++;
				} else {
					cntOne++;
				}
			}
			int num = min(cntOne, cntZero);
			if (num != B){
				OK = false;
				break;
			}
		}
	}

	//別の方法を試す
	if (!OK){
		OK = true;
		for (int ii = 0; ii < H; ++ii){
			for (int jj = 0; jj < W; ++jj){
				mat[ii][jj] = 0;
			}
		}

		for (int ii = 0; ii < B; ++ii){
			for (int jj = 0; jj < A; ++jj){
				mat[ii][jj] = 1;
			}
		}
		for (int ii = B; ii < H; ++ii){
			for (int jj = A; jj < W; ++jj){
				mat[ii][jj] = 1;
			}
		}

		//行のチェック
		for (int ii = 0; ii < H; ++ii){
			int cntZero = 0;
			int cntOne = 0;
			for (int jj = 0; jj < W; ++jj){
				if (mat[ii][jj] == 0){
					cntZero++;
				} else {
					cntOne++;
				}
			}
			int num = min(cntOne, cntZero);
			if (num != A){
				OK = false;
				break;
			}
		}
		//列のチェック
		if (OK){
			for (int jj = 0; jj < W; ++jj){
				int cntZero = 0;
				int cntOne = 0;
				for (int ii = 0; ii < H; ++ii){
					if (mat[ii][jj] == 0){
						cntZero++;
					} else {
						cntOne++;
					}
				}
				int num = min(cntOne, cntZero);
				if (num != B){
					OK = false;
					break;
				}
			}
		}
	}


	if (OK){
		for (int ii = 0; ii < H; ++ii){
			for (int jj = 0; jj < W; ++jj){
				cout << mat[ii][jj];
			}
			cout << "\n";
		}
	} else {
		cout << "No" << "\n";
	}

	return 0;
}
