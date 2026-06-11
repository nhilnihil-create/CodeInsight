#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    string _S;
    cin >> _S;
    ll Q;
    cin >> Q;
    ll rev = 0;
    deque<char> S;
    REP(i,0,SZ(_S)) S.push_back(_S[i]);
    REP(i,0,Q) {
        ll t;
        cin >> t;
        if(t == 1) rev = 1 - rev;
        else {
            ll f;
            char c;
            cin >> f >> c;
            if((rev + f-1) % 2 == 0) S.push_front(c);
            else S.push_back(c);
        }
    }
    if(rev == 0) {
        while(!S.empty()) {
            cout << S.front();
            S.pop_front();
        }
    }
    else {
        while(!S.empty()) {
            cout << S.back();
            S.pop_back();
        }
    }

    return 0;
}

/*



*/