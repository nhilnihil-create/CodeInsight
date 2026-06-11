#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "}"; return os; }

// 0, 1, 2, 3, 4,  5,  6,   7,   8,   9,   10
// 1, 1, 2, 3, 8, 15, 48, 105, 304, 945, 3040
int main(){
    LL n;
    cin >> n;
    if(n % 2 == 0){
        LL ans = 0;
        LL base = 10;
        while(base <= n){
            ans += n / base;
            base *= 5;
        }

        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}

