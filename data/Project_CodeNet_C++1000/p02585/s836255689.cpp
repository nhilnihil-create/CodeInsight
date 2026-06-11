#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <map>
#include <unordered_map>
#include <bitset>

#define _crt_secure_no_warnings
#define FREEELO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F3F3F3F3F
#define MAX 300001
#define ALPHABET 128
#define loop(i, n) for (int i = 1; i <= (n); i++)
#define loop0(i, n) for (int i = 0; i < (n); i++)
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll, ll> llll;
typedef pair<int, int> ii;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;


int main(){
    int n, k; cin >> n >> k;
    vector<int> p(n + 1), c(n + 1);
    loop(i, n) cin >> p[i];
    loop(i, n) cin >> c[i];
    ll res = -INF;
    loop(i, n){
        int a = i;
        ll c_s = 0, c_c = 0;
        while(1) { c_c++, c_s += c[a], a = p[a]; if (a == i) break; }
        ll cur = 0, cnt = 0;
        while(1) {
            cnt++, cur += c[a];
            if (cnt > k) break;
            ll ans = cur + ((k - cnt) / c_c) * max(0LL, c_s);
            res = max(res, ans); a = p[a];
            if (a == i) break;
        }
    }
    cout << res << endl;
}