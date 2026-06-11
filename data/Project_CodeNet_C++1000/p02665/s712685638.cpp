
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
int main() 
{
	
	
    int N; 
    cin >> N;
    ll rem = 1;
    ll A[N+1];
    F0R(i, N+1) 
    {
        cin >> A[i];
    }
    F0R(i, N+1) 
    {
        rem -= A[i];
        if (rem < 0) 
        {
            cout << -1 << nl; return 0;
        }
        rem *= 2; 
        if (rem > 1e15) rem = 1e15;
    }
    rem = 0;
    F0R(i, N+1) 
    rem += A[i];
    ll cur = 1;
    ll ans = 0;
    F0R(i, N+1) 
    {
        ans += min(cur, rem);
        cur -= A[i];
        cur *= 2; 
        if (cur > 1e15) cur = 1e15;
        rem -= A[i];
    }
    cout << ans << nl;
	
	return 0;
}

