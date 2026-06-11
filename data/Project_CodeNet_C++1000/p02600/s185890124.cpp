#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#pragma endregion Macros

int main()
{
    int X;
    cin >> X;

    int ans;
    if (X <= 599){
        ans = 8;
    }else if( X <= 799) {
        ans = 7;
    }else if( X <= 999){
        ans = 6;
    }else if( X <= 1199){
        ans = 5;
    }else if( X <= 1399){
        ans = 4;
    }else if( X <= 1599){
        ans = 3;
    }else if( X <= 1799){
        ans = 2;
    }else if( X <= 1999){
        ans = 1;
    }

    cout << ans << endl;
}
