#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define T() long long t;cin>>t;for(long long i=1;i<=t;i++)
#define INF (int)MAX_INT
#define INFS (int)MIN_INT
#define mod 1000000007
#define FOR(a, b, n) for(int a = b; a < n; a++)
#define REP(a,c, b) for(int a = c; a < b; a++)
#define FORD(a, b, c) for(int a = b; a >= c; a--)
#define REPD(a, c,b) for(int a = b-1; a >= c; a--)
#ifdef HOHOHO
#define DEBUG(x) cerr << #x << " : " << x << '\n'
#define DEBUGV(x) cerr << #x << " : { "; REP(_it, x.size()) cerr << x[_it] << ' '; cerr << "}" << '\n'
#define DEBUGA(x, y) cerr << #x << " : { "; REP(_it, y) cerr << x[_it] << ' '; cerr << "}" << '\n'
#define PRINTF(...) fprintf(stderr,__VA_ARGS__)
#define CHECKPOINT cerr << "OK LINE #" << __LINE__ << '\n'
#else
#define DEBUG(x) {}
#define DEBUGV(x) {}
#define DEBUGA(x, y) {}
#define PRINTF(...) {}
#define CHECKPOINT {}
#endif
#define RESET(a, b) memset(a, b, sizeof a)
#define EPS 1e-9
#define m_p make_pair
#define pb push_back
#define fi first
#define se second
#define RALL(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define ALL(x, y) x, x+y
#define SZ(x) ((int)x.size())
#define  pi(a)  pair<a, a> 
#define  vi(a)  vector<a> 
#define  vii(a) vector<pi(a)>
#define  vs vector<string>
template<class T> T sqr(T x){ return x*x; }
template<class T> T binPow(T p, int q, int MOD) {
    if(q == 1) return p % MOD;
    if(q & 1) return p*(binPow(p, q-1, MOD) % MOD) % MOD;
    else return sqr(binPow(p, q/2, MOD) % MOD) % MOD;
}
 
ll nxt() {
    ll temporaryVariable;
    cin >> temporaryVariable;
    return temporaryVariable;
}
const double PI = acos(-1.0);
#define MAXN 100001
const int G = 2e5 + 5;
 
 
 
int main(){
  ios::sync_with_stdio(false);
 
ll n=nxt(),ans=n-1;

REP(i,2,n){
    if(n%i==0){
        ans+=(n/i)-1;
    }
    else{
        ans+=n/i;
    }
}

cout<<ans<<endl;

    #ifdef HOHOHO   
    fprintf(stderr, "%.3lf\n", clock() / (double) CLOCKS_PER_SEC );
#endif
}
 

