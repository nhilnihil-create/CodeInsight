#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)
#define REP(i, n) FOR((i), 0, (n))

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T>
void print_container(T &container, string delim=" ") {
    bool first = true;
    for(auto &t: container){
        if(!first){
            cout << delim;
        }
        first = false;
        cout << t;
    }
    cout << endl;
}
const int MOD = 1e9 + 7;

ll power(int n, int p)
{
    if (p == 0)
        return 1;
    long long res = 1;
    long long add = n;
    while (p > 0)
    {
        if (p & 1)
            res = (res * add) % MOD;
        p >>= 1;
        add = add*add%MOD;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> num(k+1, 0);

    RFOR(i, k, 1){
        ll kazu = power(k/i, n);
        int j = 2;
        while(i*j<=k){
            kazu = (kazu + MOD - num[i*j]) % MOD;
            j++;
        }
        num[i] = kazu;
    }

    ll ans = 0;
    IFOR(i, 1, k)
        ans = (ans + i * num[i]) % MOD;

    cout << ans << endl;
    return 0;
}