#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;


struct Coord {
    Int x;
    Int y;
};

double CalcDist(Coord first, Coord second) {
    return sqrt((first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y));
}
double CalcDistSum(vector<Coord>& coords, vector<Int>& coordId) {
    Int size = (Int)coordId.size();
    double ret = 0;
    for (Int i = 0; i < size - 1; ++i) {
        ret += CalcDist(coords[coordId[i]], coords[coordId[i + 1]]);
    }
    return ret;
}
Int Factorial(Int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}


// ここの処理が問題によって変わる
void Func(vector<Coord>& coords, vector<Int>& v) {
    Int n = (Int)v.size();
    double sum = 0;
    do {
        sum += CalcDistSum(coords, v);
    } while (std::next_permutation(v.begin(), v.end()));
    cout << fixed << setprecision(10) << sum / (double)Factorial(n) << endl;
    return;
}

template <typename RetType, typename LoopFunc>
RetType PermutationLoop(Int n, LoopFunc loopFunc);

int main(void) {
    // 入出力処理
    Int n;
    cin >> n;
    vector<Coord> coords(n);
    for (Int i = 0; i < n; ++i) {
        cin >> coords[i].x >> coords[i].y;
    }

    // permutationループの処理(キャプチャリストは問題によって変わる)
    // PermutationLoop<Func関数の戻り値型>[キャプチャリスト](引数)->戻り値の型
    PermutationLoop<void>(n, [&coords]
            (vector<Int>& v) -> auto {
            return Func(coords, v); 
            }
            );
    return 0;
}

template <typename RetType, typename LoopFunc>
RetType PermutationLoop(Int n, LoopFunc loopFunc) {
    vector<Int> v(n);
    for (Int i = 0; i < n; ++i) {
        v[i] = i;
    }
    return loopFunc(v);
}

