#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define ALL(v) v.begin(),v.end()
const long long INF = 1LL << 60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b)
{
    if(b ==0) return a;
    return gcd(b, a%b);
}
//ABC148 C Snack
int main()
{
    ll A, B;
    cin >> A >> B;
    ll X = gcd(A, B);
    cout << A*B/X << endl;
    return 0;
}