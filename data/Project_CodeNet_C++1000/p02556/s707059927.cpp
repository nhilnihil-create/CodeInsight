#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = 2147483647;
const ld PI = 3.14159265358979323846;

//------------↓------------- M -------------- E ---------------- M --------------- O ---------------↓--------------//
// コンパイル 
// g++ -std=c++1z
//
// -------型変換--------
// int を string に変換
// string s = to_string(n);
// string を int に変換
// int n = stoi(s);
//
// -------二分探索---------
// k以上の値が最初に現れる時のイテレータ
// lower_bound(data.begin(), data.end(), k)
// kより大きい値が最初の現れる時のイテレータ O(logN)
// upper_bound(data.begin(), data.end(), k)
// kがdataに存在するかをtrue or falseで返す O(logN)
// binary_search(data.begin(), data.end(), k)
// 
//
//
//
//
//
// 
//------------↑------------- M -------------- E ---------------- M --------------- O ---------------↑--------------//




int main() {

    int N; cin >> N;
    ll x[N], y[N]; rep(i,N) cin >> x[i] >> y[i];
    ll z = x[0] + y[0];
    ll w = x[0] - y[0];
    ll z_mn = z; ll z_mx = z;
    ll w_mn = w; ll w_mx = w;

    rep(i,N) {
        z = x[i] + y[i];
        w = x[i] - y[i];
        z_mn = min(z_mn, z);
        z_mx = max(z_mx, z);
        w_mn = min(w_mn, w);
        w_mx = max(w_mx, w);
    }
    
    ll ans = max(z_mx - z_mn, w_mx - w_mn);
    cout << ans << endl;


    return 0;
}



