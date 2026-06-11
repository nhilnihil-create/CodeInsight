#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i_len=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back
#define mp make_pair

int main()
{
    ll W, H, x, y;
    cin >> W >> H >> x >> y;

    cout << setprecision(12) << W * H / 2.0 << " ";
    if(x * 2 == W && y * 2 == H) PR(1);
    else PR(0);

    return 0;
}

/*



*/