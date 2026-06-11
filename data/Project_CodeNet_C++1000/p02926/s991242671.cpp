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


ll dot(pll v1, pll v2){
    return v1.first * v2.first + v1.second * v2.second;
}

int main() {
    int n;
    cin >> n;
    vector<pll> dat(n);
    REP(i, n){
        cin >> dat[i].first >> dat[i].second;
    }
    
    ll maxx = 0;
    // ベクトルiに沿って境界線を決める
    REP(i, n){
        pll vec = dat[i];
        if(vec.first == 0 && vec.second == 0)
            continue;
        pll vec1 = make_pair(vec.second, -vec.first);
        pll vec2 = make_pair(-vec.second, vec.first);
        ll num1 = 0, num2 = 0;
        pll p1 = {0, 0}, p2 = {0, 0};
        REP(j, n){
            ll dot1 = dot(vec1, dat[j]);
            ll dot2 = dot(vec2, dat[j]);
            if(dot1 > 0 || (dot1 == 0 && dot(dat[i], dat[j]) < 0)){
                p1.first += dat[j].first;
                p1.second += dat[j].second;
            }
            if(dot2 > 0 || (dot2 == 0 && dot(dat[i], dat[j]) > 0)){
                p2.first += dat[j].first;
                p2.second += dat[j].second;
            }
        }
        num1 = dot(p1, p1);
        num2 = dot(p2, p2);
        maxx = max({maxx, num1, num2});
    }

    printf("%.14f\n", sqrt(maxx));

    return 0;
}