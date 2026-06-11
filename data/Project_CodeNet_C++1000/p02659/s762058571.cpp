#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    ll a;
    string  b;
    cin >> a >> b;
    auto pos = b.find('.');
    int prod = b.size()-pos -1;
    string c = b.substr(0, pos) + b.substr(pos+1, prod+1);
    

    ll t10 = 1;
    rep(i, prod) t10 *= 10;
    ll B = stoll(c);
    ll C = a*B;
    cout << C/t10 << endl;


    return 0;
}