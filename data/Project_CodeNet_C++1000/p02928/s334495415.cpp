#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
//head
const int nax = 2001;
ll bit[nax];

void update(int i, int v) {
    while(i < nax) {
        bit[i] += v;
        i += i & -i;
    }
}

ll sum(int i) {
    ll s = 0;
    while(i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll ans = 0;
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) { 
        cin >> a[i];
        update(a[i],1);
        ll val = (sum(nax) - sum(a[i])) * k;
        val %= mod;
        if(val < 0) val += mod;
        ans += val;
        ans %= mod;
    }
    ll val = k*(k-1);
    val %= mod;
    val *= (mod + 1) / 2;
    val %= mod;
    for(int i = 0; i < n; i++) {
        ll p1 = val*(sum(nax)-sum(a[i]));
        p1 %= mod;
        if(p1 < 0) p1 += mod;
        ans += p1;
        ans %= mod;
    }
    cout << ans % mod << endl;

    return 0;
}
