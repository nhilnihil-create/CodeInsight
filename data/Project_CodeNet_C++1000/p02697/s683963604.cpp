#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, m;
    cin >> n >> m;

    if(m==1) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }

    int l = 1, r = m + 2;
    for(int im=0;im<m;im++) {
        cout << l << " " << l+(m-im) << endl;
        l++;
        swap(l, r);
    }

    return 0;
}
