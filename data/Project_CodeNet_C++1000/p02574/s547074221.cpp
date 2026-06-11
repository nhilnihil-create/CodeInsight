#include <algorithm>
#include <bitset>
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
#include <list>
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

int a[1000005];
int cnt[1000005];
int gcd(int x, int y){
    while(y){
        x %= y;
        swap(x, y);
    }
    return x;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 2; i <= 1000000; i++){
        int k = 0;
        for(int j = i; j <= 1000000; j+= i){
            k += cnt[j];
        }
        if(k >= 2){
            int g = 0;
            for(int i = 0; i < n; i++){
                g = gcd(g, a[i]);
            }
            if(g == 1){
                cout << "setwise coprime" << endl;
            }else{
                cout << "not coprime" << endl;
            }
            return 0;
        }
    }
    cout << "pairwise coprime" << endl;
    
}
