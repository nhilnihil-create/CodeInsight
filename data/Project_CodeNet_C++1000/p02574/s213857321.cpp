#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

int main() {
    int M = 1000000;
    int n;
    cin >> n;
    vector<int> a(M+1);
    int g = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[x]++;
        g = __gcd(g, x);
    }
    int ok = 1;
    for (int i = 2; i <= M; ++i) {
        int cnt = 0;
        for (int j = i; j <= M; j += i) {
            cnt += a[j];
        }
        if(cnt >= 2){
            ok = 0;
        }
    }
    if(ok) puts("pairwise coprime");
    else if(g == 1) puts("setwise coprime");
    else puts("not coprime");
    return 0;
}