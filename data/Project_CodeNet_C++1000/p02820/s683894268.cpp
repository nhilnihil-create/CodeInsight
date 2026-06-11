#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define repi(i, n) for(int i=0;i<(int)(n);i++)
#define rep2i(i, s, n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(), v.end()

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

const ll INF = (1LL<<60);
const int INFi = (1<<29);

/*素数判定*/
bool is_prime(ll n){
    if(n==1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

/*約数列挙*/
vll enum_divisors(ll n){
    vll l;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            l.push_back(i);
            if(n/i != i) l.push_back(n/i);
        }
    }
   sort(all(l));
   return l;
}

/*素因数分解*/
vector<P> prime_factorize(ll n){
    vector<P> l;
    for(ll i=2;i*i<=n;i++){
        if(n%i!=0) continue;
        ll e = 0;
        while(n%i==0){
            e++;
            n /= i;
        }
        l.push_back({i, e});
    }
    if(n!=1) l.push_back({n, 1});
    return l;
}

int main(){

    ll n, k; cin >> n >> k;
    ll r, s, p; cin >> r >> s >> p;
    string t; cin >> t;

    vector<vector<char>> tt(k);
    rep(i, t.size()){
        tt[i%k].push_back(t[i]);
    }

    map<char, ll> cnt;
    map<char, char> win;
    win['r'] = 'p';
    win['s'] = 'r';
    win['p'] = 's';

    char old;
    rep(i, tt.size()){
        rep(j, tt[i].size()){
            if(j==0){
                cnt[win[tt[i][j]]]++;
                old = win[tt[i][j]];
            }
            else{
                if(win[tt[i][j]] != old){
                    cnt[win[tt[i][j]]]++;
                    old = win[tt[i][j]];
                }
                else{
                    old = 'x';
                }
            }
        }
    }

    cout << cnt['r']*r + cnt['s']*s + cnt['p']*p << endl;

    return 0;
}