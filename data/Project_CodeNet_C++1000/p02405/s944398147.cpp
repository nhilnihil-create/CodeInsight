#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"
 


int main() {
	while (1) {
		int H, W; cin >> H >> W;
		if (!H)break;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if ((i + j) % 2)cout << '.';
				else cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}