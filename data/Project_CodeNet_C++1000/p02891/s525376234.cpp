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
    ll K;
    cin >> K;


    vector<ll> c;
    c.push_back(1);

    for (int i = 1; i < S.size(); i++) {
        if (S[i - 1] == S[i]) 
            c[c.size() - 1]++;
        else
            c.push_back(1);
    }

    cerr << join(c) << endl;

    ll ans = 0;
    if (c.size() == 1) {
        if(S.size()%2==0){
           ans += (c[0]/2)*K;
        }else{
            ans += (c[0] * 2 / 2) * (K / 2);
            if(K%2==1)
                ans += c[0] / 2;
        }
    } else {
        if(S[0] == S[S.size()-1]){
            ans += c[0]/2;
            ans += c[c.size() - 1]/2;
            for (int i = 1; i < c.size() - 1;i++){
                ans += (c[i]/2)*K;
            }
            ans += ((c[0] + c[c.size() - 1])/2) * (K - 1);

        }else{
            for(auto a : c){
                ans += (a / 2) * K;
            }
        }
    }

    cout << ans << endl;
}
