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
    int n;
    cin >> n;
    vector<pll> x(n);
    REP(i, n){
        ll a, b;
        cin >> a >> b;
        x[i] = {a+b, a-b};
    }
    sort(x.begin(), x.end());

    int cnt = 0;
    int now = -2000000000;
    REP(i, n){
        auto next = x[i];
        if(next.second < now)
            continue;
        cnt++;
        now = next.first;
    }
    cout << cnt << endl;
    return 0;
}