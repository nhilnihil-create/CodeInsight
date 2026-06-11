#include <bits/stdc++.h>
#define repl(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int x,y;
    cin >> x >> y;
    ll sum = 0;
    if(x < 4)sum += (4-x)*100000;
    if(y < 4)sum += (4-y)*100000;
    if(x == y && x == 1)sum += 400000;
    cout << sum << endl;
    return 0;
}