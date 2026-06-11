#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = unsigned long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    ll x;
    cin >> x;

    int m = 2000;
    vl A(m);
    rep2(i, 0, m) {
        ll p = i;
        A[i] = p*p*p*p*p;
    }
    rep2(i, 0, m)rep2(j, 0, m)
    {
        ll y = A[i] - A[j];
        if(y == x)
        {
            cout << i << " " << j << endl;
            return 0;
        }
        y = A[i]+ A[j];
        if(y == x)
        {
            cout << i << " " << -j << endl;
            return 0;
        }
    }
    return 0;
}