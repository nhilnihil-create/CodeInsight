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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<int> mp(n+1);
    rep(i,n){
        mp[a[i]]++;
    }
    vector<int> cnt(n + 1, 0);
    for(auto x : mp){
        cnt[x]++;
    }
    show(cnt);
    int all = n;
    for(int k = 1; k <= n; k++){
        int x = all / k;
        //x枚以上あるやつは無駄
        show(k, x, all, cnt.size());
        while((int) cnt.size() - 1 > all / k){
            if(cnt.back() == 0){
                cnt.pop_back();
                continue;
            }
            all--;
            cnt.back()--;
            cnt[cnt.size() - 2]++;
            if(cnt.back() == 0)cnt.pop_back();
        }
        show(all);
        show(cnt);
        cout << all / k << "\n";
    }
}

