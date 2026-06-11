#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;
/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
*/
//#define sqr(qwert) qwert * qwert
#define eb emplace_back
#define pb push_back
#define ld long double
#define ll long long
#define f first
//#define s second
#define deb(a) cerr << #a << " = " << a << '\n';
#define fast() { \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); \
    cout << fixed << setprecision(15); \
    cerr << fixed << setprecision(11); \
}

const int INF = 1e9 + 7;
const ld EPS = 1e-10;
const int MAXI = 20000;
const int MOD = 998244353;
const int MAXST = 2000000;
const int P = 62;
const ld PI = 3.14159265358979323;

int main() {
    ll a, b, n, l = 0, r = 1e12, maxx = 0, k = 0;
    cin >> a >> b >> n;
    do{
        ll m = (l + r) / 2;
        if(a * m / b - a * (m / b) > maxx){
            if(m > n){
                r = m;
            }
            else{
                maxx = a * m / b - a * (m / b);
                l = m + 1;
            }
        }
        else r = m;
    }while(l != r);
    cout << maxx << '\n';
    return 0;
}