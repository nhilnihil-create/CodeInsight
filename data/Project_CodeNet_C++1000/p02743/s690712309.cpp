#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (ll i = 0; i < (o);i++)
#define rep_s(i, o) for (int i = 1; i <= (o);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


template<class T>
bool chmax(T &a, const T &b) {
    if (a < b)
    {
        return b;
    }
    return a; 
}

template<class T>
bool chmin(T &a, const T &b) {
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0; 
}

int main() {
    long double a, b, c;
    cin >> a >> b >> c;

    // if (a >= 1e8 || b >= 1e8 || c >= 1e8) a /= 100; b /= 100; c /= 10000;
    // cout << (a) << " " << (b) << " " << (c) << endl;
    string ans = (a + b + 2*(sqrt(a) * sqrt(b)) < c) ? "Yes" : "No";
    // cout << 2*(sqrt(a) * sqrt(b)) << " " << c << endl;
    cout << ans << endl;
    return 0;
}