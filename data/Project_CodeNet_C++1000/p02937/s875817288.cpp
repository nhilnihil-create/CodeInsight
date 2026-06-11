#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

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
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define REV(x) reverse(ALL((x)))
#define pb push_back

int main()
{
    string s, t;
    cin >> s >> t;

    ll Ns = SZ(s), Nt = SZ(t);
    map<char,vec> A;
    map<char,ll> I;
    REP(i,0,Ns) A[s[i]].pb(i);
    REP(i,0,26) I['a'+i] = 0;

    /*
    FORR(a,A) {
        PS(a.first);
        FORR(i,a.second) PS(i);
        PR("");
    }
    */

    ll j, k = 1;
    ll idx = -1, prev = 0;
    REP(i,0,Nt) {
        if(SZ(A[t[i]]) == 0) {
            k = -1;
            break;
        }
        I[t[i]] = upper_bound(ALL(A[t[i]]), idx) - A[t[i]].begin();
        if(I[t[i]] == SZ(A[t[i]])) {
            I[t[i]] = 0;
            idx = A[t[i]][I[t[i]]];
            k += Ns - prev + idx;
        }
        else {
            idx = A[t[i]][I[t[i]]];
            k += idx - prev;
        }
        // cout << t[i] << ":" << A[t[i]][I[t[i]]] << " ";
        prev = idx;
    }
    PR(k);

    return 0;
}

/*



*/