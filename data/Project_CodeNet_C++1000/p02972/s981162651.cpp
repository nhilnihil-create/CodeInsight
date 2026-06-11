#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define repi(i, n) for(int i=0;i<(int)(n);i++)
#define rep2i(i, s, n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(), v.end()

#define deg2rad(deg) (((deg)/360)*2*M_PI)
#define rad2deg(rad) (((rad)/2/M_PI)*360)

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

/*最小公倍数*/
ll lcm(ll a, ll b){
    return a*b/__gcd(a,b);
}

/*最大公約数*/
ll gcd(ll a, ll b){
    return __gcd(a,b);
}

int main(){

    ll n; cin >> n;
    ll in;
    vector<bool> a(n+1, false);
    rep2(i, 1, n+1){
        cin >> in;
        a[i] = !!in;
    }

    ll sum = 0;
    vector<bool> ans(n+1);
    for(ll i=n;i>0;i--){
        bool b = a[i];
        for(ll j=1;j<n+1;j++){
            if(i*j>n) break;
            b ^= ans[i*j];
        }
        ans[i] = b;
        if(b) sum++;
    }

    cout << sum << endl;
    rep2(i, 1, n+1){
        if(ans[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}