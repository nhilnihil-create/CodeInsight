#include <bits/stdc++.h>
#define Phuong_ ios_base::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a; i<=b; ++i)

/// easy access -------------
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<int,int> pi;
typedef tuple<bool, int, int> tp;
typedef vector<vector<int>> vv;
///-------------------------


int main()
{
    Phuong_; /// <3333
    ll d,k,x;
    cin >> x >> k >> d;
    if (abs(x)%d == 0) {
        if (abs(x)/d > k) cout << abs((x < 0 ? (x + k*d) : (x-k*d))); else {
            k-= abs(x)/d ;
            if (k&1) cout << d; else
            cout << 0;
        }
    } else {
        if (abs(x)/d > k ) cout << abs((x < 0 ? (x + k*d) : (x-k*d))); else {
            ll num = abs(x) / d;
            if (x<0) x += num*d; else {
                x -= num*d;
            }
            k-=num;
            if (k&1) {
                if (x<0) x+=d;
                else x-=d;
                cout << abs(x);
            } else cout << abs(x);
        }
    }
    return 0;
}
