#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll h1, m1, h2, m2, k, a, b;

    cin >> h1 >> m1 >> h2 >> m2 >> k;

    a = h1*60+m1;
    b = h2*60+m2;

    cout << b-a-k << endl;

    return 0;
}