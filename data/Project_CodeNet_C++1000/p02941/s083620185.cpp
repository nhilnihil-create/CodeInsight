/*
ЗАПУСКАЕМ
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 200228;


int n;
int a[MAXN], b[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    set<pair<int, int> > s;
    for (int i = 0; i < n; i++) {
        s.insert({b[i], i});
    }
    long long res = 0;
    while (!s.empty()) {
        auto x = *s.rbegin();
        if (x.first == a[x.second]) {
            s.erase(x);
            continue;
        }
        if (x.first < a[x.second]) {
            cout << -1 << endl;
            return 0;
        }
        int f = b[(x.second + n - 1) % n];
        int f1 = b[(x.second + 1) % n];
        if (f + f1 > x.first) {
            cout << -1 << endl;
            return 0;
        }
        s.erase(x);
        int g = a[x.second];
        if (b[x.second] % (f + f1) >= g) {
            res += b[x.second] / (f + f1);
            b[x.second] %= (f + f1);
            s.insert({b[x.second], x.second});
            continue;
        }
        int t = (b[x.second] - g) / (f + f1);
        if (t == 0) {
            cout << -1 << endl;
            return 0;
        }
        res += t;
        b[x.second] -= (f + f1) * (t);
        s.insert({b[x.second], x.second});
    }
    cout << res << endl;
    return 0; 
}

