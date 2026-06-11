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

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros

int main()
{
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;

    A--;B--;
    C--;D--;

    if(A>B){
        swap(A,B);
        swap(C,D);
    }

    for (int i = A;i<C;i++){
        if(S[i] == '#' && S[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = B;i<D;i++){
        if(S[i] == '#' && S[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }

    if(C>D){
        for (int i = B;i<=D;i++){
            if(S[i-1] == '.' && S[i]=='.' && S[i+1]=='.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
