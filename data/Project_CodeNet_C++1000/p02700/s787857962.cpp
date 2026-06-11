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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while(1){
        c -= b;
        if(c <= 0)
        {
            cout << "Yes" << endl;return 0;
        }
        a -= d;
        if(a <= 0)
        {
            cout << "No" << endl;return 0;
        }

    }
    return 0;
}