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

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> ans(n);
    if(s != 1000000000){
        REP(i, k)
            ans[i] = s;
        FOR(i, k, n)
            ans[i] = s+1;
    }
    else{
        REP(i, k){
            ans[i] = s;
        }
        FOR(i, k, n)
            ans[i] = 1;
    }

    REP(i, n)
        cout << (i==0?"":" ") << ans[i];
    cout << endl;
    return 0;
}