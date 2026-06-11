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
    ll x;

    cin >> x;

    if(x<600) cout << 8 << endl;
    else if(x<800) cout << 7 << endl;
    else if(x<1000) cout << 6 << endl;
    else if(x<1200) cout << 5 << endl;
    else if(x<1400) cout << 4 << endl;
    else if(x<1600) cout << 3 << endl;
    else if(x<1800) cout << 2 << endl;
    else cout << 1 << endl;

    return 0;
}