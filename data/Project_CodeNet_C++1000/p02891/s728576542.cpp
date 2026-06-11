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
    string S;
    ll K;
    cin >> S >> K;

    bool f = true;
    REP(i,1,SZ(S)) {
        if(S[i] != S[0]) {
            f = false;
            break;
        }
    }

    if(f) {
        PR(K*SZ(S)/2);
    }
    else {
        string T = S + S;
        ll cnt1 = 0, cnt2 = 0;
        REP(i,0,SZ(S)-1) {
            if(S[i] == S[i+1]) {
                ++cnt1;
                ++i;
            }
        }
        REP(i,0,SZ(T)-1) {
            if(T[i] == T[i+1]) {
                ++cnt2;
                ++i;
            }
        }
        PR(cnt1+(cnt2-cnt1)*(K-1));
    }

    return 0;
}

/*

*/