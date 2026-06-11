#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ","){
    if(v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for(int i=1;i<v.size();i++){
        res << delim << v[i];
    }
    return res.str();
}

#pragma endregion Macros

int main()
{
    int N;
    string S;
    cin >> N >> S;

    vector<int> s(N);

    rep(i,N){
        if(S[i]=='R')
            s[i] = 0;
        else if(S[i]=='G')
            s[i] = 1;
        else
            s[i] = 2;
    }

    vector<vector<ll>> sum(3, vector<ll>(N + 1 , 0));

    rep(i,N){
        rep(c,3){
            sum[c][i + 1] = sum[c][i];
            if(c == s[i])
                sum[c][i + 1]++;
        }
    }

//    cerr << join(sum[0]) << endl;
//    cerr << join(sum[1]) << endl;
//    cerr << join(sum[2]) << endl;

    ll ans = 0;
    rep(i, N) FOR(j, i+1, N)
    {
        if(s[i] == s[j])
            continue;

        vector<bool> b(3,true);
        b[s[i]] = false;
        b[s[j]] = false;
        
        char x = b[0]? 0 : b[1]?1 : 2;

        ans += sum[x][N] - sum[x][j + 1];

        int k = j - i;
        if(j+k < N)
            ans -= sum[x][j + k + 1] - sum[x][j + k];

    }

    cout << ans << endl;
}
