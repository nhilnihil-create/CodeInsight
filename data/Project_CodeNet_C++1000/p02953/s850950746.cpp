#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
using namespace std;
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using ll = long long;
using P  = pair<int, int>;
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int n;
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];
    reverse(ALL(h));
    rep2(i, 1, n){
        if(h[i-1] >= h[i] ) continue;
        h[i] -=1;
        if(h[i-1] >= h[i] ) continue;
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;


    return 0;
}