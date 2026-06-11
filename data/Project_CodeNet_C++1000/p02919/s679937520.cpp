/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 62;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll conbinationMemo[100][100];

ll cmemoInit(){
    rep(i, 100){
        rep(j, 100){
            conbinationMemo[i][j] = -1;
        }
    }
}
 
ll nCr(ll n, ll r){
    if(conbinationMemo[n][r] != -1) return conbinationMemo[n][r];
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return conbinationMemo[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
int main(void){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    vector<int> pos(n + 1);

    rep(i, n){
        pos[p[i]] = i + 1;
    }

    multiset<int> st;
    st.insert(pos[n]);
    st.insert(n + 1);
    st.insert(n + 1);
    st.insert(0);
    st.insert(0);
    ll ans = 0;
    for(int i = n - 1; i >= 1; i--){
        int nowidx = pos[i];
        auto itr = st.lower_bound(nowidx);
        auto a = itr;
        auto a2 = ++itr;
        itr = st.lower_bound(nowidx);
        auto b = --itr;
        auto b2 = --itr;
        //cout << i << endl;
        //cout << *b2 << " " << *b << " " << nowidx << " " << *a << " " << *a2 << endl;
        ll tmp = (*a - nowidx) * (*b - *b2);
        tmp += (nowidx - *b) * (*a2 - *a);
        ans += tmp * i;
        st.insert(nowidx);
    }

    cout << ans << endl;
}