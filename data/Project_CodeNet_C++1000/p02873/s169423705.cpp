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






int main(void) {

    string s; cin >> s;
    int n = s.size() + 1;
    int l[n], r[n]; rep(i,n) l[i] = r[i] = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') l[i+1] = l[i] + 1;
        else l[i+1] = 0;
    }
    for (int i = n - 1; i > 0; --i) {
        if (s[i-1] == '>') r[i-1] = r[i] + 1;
        else r[i-1] = 0;
    }
    ll ans = 0;
    rep(i,n) ans += max(l[i], r[i]);
    out(ans);



    return 0;
}







