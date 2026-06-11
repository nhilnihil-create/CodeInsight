#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;

const ll mod = 1000000000 + 7; //10^9


// bool is_integer(double x){
//     return floor(x) == x;
// }

// vector<int> bitsearch(int n, int bit) {
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> S(n);
//         if(bit & (1 << i)){
//             S.push_back(i);
//         }
//     }
// }./  

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll b_c = 0;
    b_c = N / (A + B);
    N -= b_c * (A + B);
    ll ans = 0;
    if(N > A) {
        ans += A;
    }else{
        ans += N;
    }
    ans += b_c * A;
    cout << ans << endl;
}
