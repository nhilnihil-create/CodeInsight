#include<iostream>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define endl "\n"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const ll mod = 1000000007;
const string YES = "Yes";
const string NO = "No";
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll a[100100];

ll modpow(ll a, ll x){
    if(x == 0)return 1;
    if(x % 2 == 0){
        ll t = modpow(a, x/2);
        return t * t % mod;
    }
    return a * modpow(a, x-1) % mod;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    for(int i=k;i>=1;i--){
        ll t = k / i;//iの倍数の数
        a[i] = modpow(t, n);
        if(a[i]<0){
            cout << NO;
        }

        for(int j=i+i;j<=k;j+=i){
            a[i] -= a[j];
            if(a[i] < 0)a[i] += mod;
        }   
    }
    ll ans = 0;
    for(int i=1;i<=k;i++) {
        ans += a[i] * i;
        ans %= mod;
    }
    cout << ans << endl;
}