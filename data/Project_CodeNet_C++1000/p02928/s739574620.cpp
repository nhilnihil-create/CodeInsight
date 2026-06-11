#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
ll mod = 1000000007;

signed main(){
    int n; ll k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<ll> cnt_1(n),cnt_2(n);
    rep(i,n){
        int c1 = 0, c2 = 0;
        for(int j = i+1; j < n; ++j){
            if(a[i] > a[j]) c1++;
        }
        rep(j,n) if(a[i] > a[j]) c2++;
        cnt_1[i] = c1;
        cnt_2[i] = c2;
    }

    ll ans = 0;
    ll K = (((k-1) * k) / 2) % mod;
    rep(i,n){
        ans += (cnt_1[i] * k) % mod;
        ans += (cnt_2[i] * K) % mod;
        ans %= mod;
    }

    cout << ans % mod << endl;
}

