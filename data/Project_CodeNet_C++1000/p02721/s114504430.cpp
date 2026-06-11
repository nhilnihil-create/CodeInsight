#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    llint n, c, k;
    cin >> n >> c >> k;
    string s;
    cin >> s;

    list<int> l;
    list<int> r;
    for(int in=1;in<=n;in++) {
        if(s[in-1]=='o') {
            l.push_back(in);
            in += k;
        }
    }
    int cnt=0;
    for(int in=n;in>=1;in--) {
        if(s[in-1]=='o') {
            r.push_front(in);
            in -= k;
            cnt++;
        }
        if(cnt==c) break;
    }
    int cmax = min(l.size(), r.size());
    auto itrl = l.begin();
    auto itrr = r.begin();
    for(int ic=0;ic<cmax;ic++) {
        if(*itrl==*itrr) cout << *itrl << endl;
        itrl++;
        itrr++;
    }
    return 0;
}
