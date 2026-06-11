#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);


int main() {
    ll n, m; cin >> n;
    vector<ll> A, B;
    vector<P> ans;

    rep(i, n) {
        ll x; cin >> x;
        if(x < 0) A.push_back(x);
        else B.push_back(x);
    }
    ll a = A.size(), b = B.size();
    sort(ALL(A));
    sort(ALL(B));

    if(a > 0 && b > 0) {
        frep(i, 1, b-1) {
            ans.push_back(make_pair(A[0], B[i]));
            A[0] -= B[i];
        }
        rep(i, a) {
            ans.push_back(make_pair(B[0], A[i]));
            B[0] -= A[i];
        }
        m = B[0];
    }
    else if(a == 0) {
        frep(i, 2, b-1) {
            ans.push_back(make_pair(B[0], B[i]));
            B[0] -= B[i];
        }
        ans.push_back(make_pair(B[1], B[0]));
        B[1] -= B[0];
        m = B[1];
    }
    else if(b == 0) {
        rep(i, a-1) {
            ans.push_back(make_pair(A[a-1], A[i]));
            A[a-1] -= A[i];
        }
        m = A[a-1];
    }

    cout << m << endl;

    rep(i, n-1) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }


    /*
    sort(ALL(B));
    ll b = B.size();
    rep(i, b/2) {
        ans.push_back(make_pair(B[i], B[b-1-i]));
        A.push_back(B[i] - B[b-1-i]);
    }

    sort(ALL(A));
    ll a = A.size();
    if((b%2) == 1) {
        m = B[b/2];
        rep(i, a) {
            ans.push_back(make_pair(m, A[i]));
            m = m - A[i];
        }
    }
    else {
        m = A[a-1];
        rep(i, a-1) {
            ans.push_back(make_pair(m, A[i]));
            m = m - A[i];
        }
    }

    cout << m << endl;
    rep(i, n-1) {
        ll x = ans[i].first, y = ans[i].second;
        cout << x << " " << y << endl;
    }
    */

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
