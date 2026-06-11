/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
			　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <memory>
#include <iomanip>

#define rep(i, n) for(Int (i) = 0; (i) < (n); ++(i))
#define debug(var) std::cout << #var << ": " << var << "\n"
using Int = int64_t;
constexpr Int INF = INT_MAX;
constexpr Int mod = 1e9 + 7;


void calc() {

	Int H, W, A, B; std::cin >> H >> W >> A >> B;
	rep(i, H){
		rep(j, W) {
			if (i <= H - B - 1) {
				if (j <= W - A - 1)std::cout << 0;
				else std::cout << 1;
			}
			else {
				if (j <= W - A - 1)std::cout << 1;
				else std::cout << 0;
			}
		}
		std::cout << "\n";
	}

}


int main() {

	calc();

	return 0;
}