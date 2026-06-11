#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <algorithm>

#define MOD_BIG 1000000007
#define MOD_BIG2 998244353
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;
using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using std::vector;

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

//////////////////////////////////////



//////////////////////////////////////

int main() {
    
    int N;
    cin >> N;
    vector<ll> A(N);
    std::multiset<ll> ms;
    int cnt = 0;
    REP(i, N) {
        cin >> A[i];
        ms.insert(A[i]);
        if (A[i] < 0) {
            cnt++;
        }
    }
    std::sort(A.begin(), A.end());
    int M = 0;
    if (cnt == 0) {
        M -= A[0];
        FOR(i, 1, N) {
            M += A[i];
        }
        cnt = 1;
    } else if (cnt == N) {
        M += A[N-1];
        IFOR(i, 0, N-1) {
            M -= A[i];
        }
        cnt = N-1;
    } else {
        REP(i, N) {
            M += std::abs(A[i]);
        }
    }
    cout << M << endl;
    ll x, y;
    std::queue<ll> tmp;
    FOR(i, 0, N-cnt-1) {
        y = *ms.begin();
        x = *std::prev(ms.end());
        cout << y << " " << x << endl;
        ms.erase(ms.begin());
        ms.erase(std::prev(ms.end()));
        ms.insert(y-x);
    }
    FOR(i, 0, cnt) {
        y = *std::prev(ms.end());
        x = *ms.begin();
        cout << y << " " << x << endl;
        ms.erase(std::prev(ms.end()));
        ms.erase(ms.begin());
        ms.insert(y-x);
    }
    
    return 0;
}
