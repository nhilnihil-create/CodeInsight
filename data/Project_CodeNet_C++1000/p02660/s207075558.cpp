#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


struct Sieve { // 篩
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; ++i) {
            if (f[i]) continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i*i; j <= n; j += i) {
                if (!f[j]) f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x;} // 素数判定
    vector<int> factorList(int x) { // 素因数列挙
        vector<int> res;
        while (x != 1) {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<P> factor(int x) { // 素因数分解 int        
        vector<P> res;
        for(int p : primes) {
            int y = 0;
            while(x % p == 0) x /= p, y++;
            if(y != 0) res.emplace_back(p,y);
        }
        return res;
    }
    vector<pair<ll, int>> factorll(ll x) { // 素因数分解 long long 
        vector<pair<ll, int>> res;
        for(int p : primes) {
            int y = 0;
            while(x % p == 0) x /= p, y++;
            if(y != 0) res.emplace_back(p,y);
        }
        if(x != 1) res.emplace_back(x,1);
        return res;
    }
};


int main(){
    ll n;
    cin >> n;
    Sieve s(2000000);
    auto fl = s.factorll(n);
    int ans = 0;
    for(auto p : fl) {
        int c = p.se;
        int b = 1;
        while(b <= c) {
            c -= b;
            b++;
            ans++;
        }
    }
    cout << ans << endl;
}