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

int main() {
    int n;
    cin >> n;
    vector<pll> vec(n);
    REP(i, n){
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end(), [](pll &p1, pll &p2){return atan2(p1.second, p1.first) < atan2(p2.second, p2.first);});

    ll maxx = 0;
    FOR(i, 0, n){
        IFOR(j, 1, n){
            pll now = make_pair(0, 0);
            FOR(k, 0, j){
                int idx = (i + k) % n;
                now.first += vec[idx].first, now.second += vec[idx].second;
            }
            maxx = max(maxx, now.first * now.first + now.second * now.second);
        }
    }

    printf("%.14f\n", sqrt(maxx));

    return 0;
}