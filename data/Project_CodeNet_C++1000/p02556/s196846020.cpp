#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define FILL0(x) memset(x,0,sizeof(x))
#define FILL1(x) memset(x,-1,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    ll max1, min1;
    ll max2, min2;
    max1=max2=-1e10;
    min1=min2=1e10;
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        chmax(max1, x+y);
        chmin(min1, x+y);
        chmax(max2, x-y);
        chmin(min2, x-y);
    }
    cout << max(max1-min1, max2-min2) << endl;    

    return 0;

}
