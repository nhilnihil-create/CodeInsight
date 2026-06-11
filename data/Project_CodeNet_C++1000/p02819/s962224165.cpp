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

// エラトステネスの篩(sieve of eratosthenes)を用いて素数判定テーブルを作成する
// O(n loglog n) worst time, O(n) word space
vector<bool> MakePrimeChecker(const Int size) {
    vector<bool> table(size, true);
    table[0] = false;
    table[1] = false;
    Int loop = sqrt(size);
    for (Int i = 2; i <= loop; ++i) {
        if (table[i] == true) {
            Int j = 2;
            while (i * j < size) {
                table[i * j] = false;
                ++j;
            }
        }
    }
    return table;
}

int main(void) {
    Int x;
    cin >> x;
    const Int TABLE_SIZE = 100004;
    vector<bool> prime_table = MakePrimeChecker(TABLE_SIZE);
    for (Int i = x; i < TABLE_SIZE; ++i) {
        if (prime_table[i] == true) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
