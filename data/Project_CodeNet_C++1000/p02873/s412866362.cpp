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
    string S;
    cin >> S;

    int N = S.size() + 1;
    vector<int> ans(N,-1);

    if (S[0] == '<') ans[0] = 0;
    if (S[S.size() - 1] == '>') ans[ans.size() - 1] = 0;

    for(int i=0;i<S.size()-1;i++){
//        cerr << S[i] << "," << S[i + 1] << endl;
        if (S[i] == '>' && S[i + 1] == '<') {
            ans[i + 1] = 0;
        }
    }
//    cerr << join(ans) << endl;

    for(int i=0;i<S.size();i++){
        if (S[i] == '<' && ans[i] >= 0) ans[i + 1] = ans[i] + 1;
    }

//    cerr << join(ans) << endl;

    for (int i = S.size()-1;i>=0;i--){
        if (S[i] == '>' && ans[i + 1] >= 0) chmax(ans[i], ans[i + 1] + 1);
    }

//    cerr << join(ans) << endl;

    ll res = 0;
    for(auto n : ans){
        res += n;
    }

    cout << res << endl;

}
