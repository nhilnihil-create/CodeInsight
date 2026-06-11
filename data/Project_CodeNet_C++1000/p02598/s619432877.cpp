#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <list>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    
    int ok = 1e9;
    int ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        int cnt = 0;
        rep(i,n){
            cnt += max(0,(a[i] + mid - 1)/mid-1);
        }
        if(cnt <= k)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
