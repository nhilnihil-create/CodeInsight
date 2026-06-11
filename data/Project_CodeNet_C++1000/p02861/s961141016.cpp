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
double CalcDist(Coord first, Coord second);
double CalcDistSum(vector<Coord>& coords, vector<Int>& coordId);
Int Factorial(Int n);

/*
// 引数に関数オブジェクトを渡さない場合
void PermutationLoop(Int n, vector<Coord>& coords) {
    vector<Int> v(n);
    for (Int i = 0; i < n; ++i) {
        v[i] = i;
    }

    //double (*const calcDistSum[])(vector<Coord>&, vector<Int>&) = {CalcDistSum}; // 関数ポインタ
    // 関数オブジェクト(ラムダ式使用) ver.1
    // auto calcDistSum = [&coords, &v]() {
    //     return CalcDistSum(coords, v);
    // };
    // 関数オブジェクト(ラムダ式使用) ver.2
    // auto calcDistSum = [&v](vector<Coord>& coords) {
    //     return CalcDistSum(coords, v);
    // };

    double sum = 0;
    do {
        //sum += calcDistSum[0](coords, v); // 関数ポインタ
        //sum += calcDistSum(); // 関数オブジェクト ver.1
        sum += calcDistSum(coords); // 関数オブジェクト ver.2
    } while (std::next_permutation(v.begin(), v.end()));
    cout << fixed << setprecision(10) << sum / (double)Factorial(n) << endl;
    return;
}

*/
// 引数に関数オブジェクトを渡す場合
template <typename Func>
void PermutationLoop(Int n, Func func) {
    vector<Int> v(n);
    for (Int i = 0; i < n; ++i) {
        v[i] = i;
    }
    double sum = 0;
    do {
        sum += func(v); // 関数オブジェクト ver.3
    } while (std::next_permutation(v.begin(), v.end()));
    cout << fixed << setprecision(10) << sum / (double)Factorial(n) << endl;
    return;
}


int main(void) {
    Int n;
    cin >> n;
    vector<Coord> coords(n);
    for (Int i = 0; i < n; ++i) {
        cin >> coords[i].x >> coords[i].y;
    }
    // 関数オブジェクト(ラムダ式使用) ver.3: 引数で渡す
    auto calcDistSum = [&coords](vector<Int>& v) {
        return CalcDistSum(coords, v);
    };

    PermutationLoop(n, calcDistSum);
    return 0;
}

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

