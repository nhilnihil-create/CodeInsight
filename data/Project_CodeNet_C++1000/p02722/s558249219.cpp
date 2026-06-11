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
    llint n;
    cin >> n;

    llint ans = 0;
    for(llint in=1;in*in<=n-1;in++) {
        if((n-1)%in==0) {
            ans += 2;
        }
        if(in*in==n-1) ans--;
    }
    ans--;

    vector<llint> ndiv;
    for(llint in=1;in*in<=n;in++) {
        if(n%in==0) {
            if(in!=1) ndiv.push_back(in);
            if(in*in!=n)ndiv.push_back(n/in);
        }
    }

    llint ntmp;
    for(auto k:ndiv) {
        ntmp = n;
        while(ntmp%k==0) {
            ntmp /= k;
        }
        if(ntmp%k==1) ans++;
    }

    cout << ans << endl;
    return 0;
}
