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
    int A,B,C;
    cin >> A >> B >> C;
    int K;
    cin >> K;

    int cnt = 0;

    while(B <= A) {
        B *= 2;
        cnt++;
    }
    while( C<=B){
        C*=2;
        cnt++;
    }

    string ans;
    if (cnt <= K) {
        ans = "Yes";
    }else{
        ans = "No";
    }

    cout << ans << endl;
}
