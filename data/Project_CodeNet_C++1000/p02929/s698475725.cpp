#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

void addM(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(long long &a, long long b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

// a^b mod M
long myPow(long a,long b,int M) {
    long ret = 1;
    long tmp = a;
    while(b>0) {
        if((b&1)==1) ret = (ret * tmp) % M;
        tmp = (tmp * tmp) % M;
        b = b>>1;
    }
    return ret;
}

 // nCk mod M
int nCk(int n,int k,int M) {
    long ret = 1;
    int mi = min(k, n-k);
    for(int i=1;i<=mi;i++) {
        ret = (ret * myPow(i,M-2,M)) % M;
    }
    for(int i=n-mi+1;i<=n;i++) {
        ret = (ret * i) % M;
    }
    return (int)ret;
};

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}


int main() {
    int N;
    string s;

    cin >> N >> s;

    vector<int> v(2 * N, 0);
    for (int i = 2 * N - 1; i > 0; i--) {
        v[i - 1] = v[i] + 1;
    }

    int num_b = 0;
    REP(i, 2 * N) {
        if (s[i] == 'B') v[i] += 1;
        v[i] %= 2;
        if (v[i]) num_b++;
    }

    ll ans = 0;
    if (num_b == N) {
        ans = 1;

        int num_w = 0;
        REP(i, N * 2) {
            if (v[i] == 0) num_w++;
            else (ans *= num_w--) %= MOD;
        }
    }

    ll np = 1;
    REP(i, N) mulM(np, i + 1);

    cout << (ans * np) % MOD << endl;

    return 0;
}