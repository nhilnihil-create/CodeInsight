#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#define int long long
#define _CRT_SECURE_NO_WARNINGS
#define rep(i, n) for (int i = 0; i < n; i++)
#define _GLIBCXX_DEBUG
const int MOD = 1e9 + 7;
const int INF = 1e18 + 9;
constexpr long double pi = 3.141592653589793238462643383279; //円周率
/*---------------------便利な関数--------------------------------------*/
int fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i;
}

int gcd(int a, int b) {        //最大公約数
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {      //最小公倍数
    return a * b / gcd(a, b);
}

int keta(int n) {        //桁数を求める
    if (n == 0) return 1;
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int ketasum(int n) {    //各桁の和
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/*-------------ここまで---------------------------------------------*/
//C++(GCC9.2.1)
/*---------------------文法の確認--------------------*/
//vector<型> 配列名(要素数, 初期値);    //初期値の指定
//配列変数.push_back(何とか）　　　　　　//配列の末尾に要素を追加
//配列変数.pop_back                    //配列の末尾の要素を削除
//sort(vec.begin(), vec.end())        //配列変数vecをソートする（要素を小さい順に並び替える
//reverse(vec.begin(), vec.end())     //配列変数vecの要素の並びを逆にする
//返り値の型 関数名(引数1の型 引数1の名前, 引数2の型 引数2の名前, ...) { //
//  処理                                                             //関数定義
//}                                                                 //
//参照先の型 &参照の名前 = 参照先;      //参照
/*int sum(int n) {
    if (n == 0) {
        return 0;
    }
                                                                    //再帰関数の例
    // sum関数の中でsum関数を呼び出している
    int s = sum(n - 1);
    return s + n;
}*/

/*---------------------終わり----------------------------------------------*/

//宣言

signed main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k <= a) cout << k << endl;
    else if (k <= a) cout << a << endl;
    else cout << a - (k - a - b) << endl;
    return 0;
}