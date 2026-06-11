// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
 
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <time.h>
#include <stack>
#include <bitset>

#define prev asasddlsa
#define rank aljds

#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i >= l; i++)
 
using namespace std;
 
typedef long long ll;
typedef long double dbl;
 
template<typename T>
void print(const vector<T>& s){
    for (auto x : s)
        cout << x << ' ';
    cout << endl;
}
 
template<class T>   
void print(const T* s, int n){
    for (int i = 0; i < n; i++)
        cout << s[i] << ' ';
    cout << endl;
}
 
template<class T>
void print(vector<vector<T>> s){
    for (int i = 0; i < s.size(); i++)
        print(s[i]);
}

void solve(){
    int n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    int l = -1, r = n - 1;
    while (l + 1 < r){
        int med = (l + r) / 2;
        ll summa = 0, cnt = 0;
        bool ok = true;
        for (int i = med + 1; i < n - p + 1; i++){
            if (s[i] > s[med] + m){
                ok = false;
                break;
            }
            summa += s[med] + m - s[i];
            cnt++;
        }
        if (ok && summa >= (ll)m * max(0, v - med - 1 - p + 1))
            r = med;
        else
            l = med;
    }
    cout << n - r << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
