#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#define rep(i, f, t) for(int i=(int)(f); i<(int)(t); i++)
#define rrep(i, f, t) for(int i=(int)(f); i>(int)(t); i--)
using namespace std;
using ll = long long;
#define MOD 1000000007
#define MOD2 998244353
constexpr int INFINT = (1 << 30) - 1;       // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1; // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;             // 1.15x10^18
typedef pair<ll, ll> P;
template<class T> inline T chmax(T& a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

/*dp[i][j] */

/*def*/
string ret;
ll k;

int main() {
/*input*/
    cin >> k;
/*main*/
    rep(i, 0, k)ret += "ACL";
/*output*/
    cout << ret << endl;
    return 0;
}
