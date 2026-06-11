#include <bits/stdc++.h>

using namespace std;

#define forn for (ll i = 0; i < n; i++)
#define form for (ll j = 0; j < m; j++)
#define NO cout << "NO\n";
#define YES cout << "YES\n";
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i < b; i++)

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

ll gcd(ll a, ll b){
    ll r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


ll *calc_z(string s){
    ll n = s.size();
    ll *z = new ll[n] {0};
    ll l = 0, r = 0;
    for (ll i = 1; i < n; i++){
        if (r >= i) z[i] = min(z[i-l], r-i+1);
        while (z[i]+i < n && s[z[i]] == s[z[i]+i]) z[i]++;
        if (i + z[i] - 1 > r){
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int find_lower(int *a, int n, int v){
    int l = -1, r = n;

    while (r-l > 1){
        int m = (l+r)/2;
        if (a[m] <= v) l = m;
        else r = m;
    }
    return l;
}

void init(){
}

int bin(int *p, int n, int x){
    int l = 0, r = n-1;
    while (r >= l){
        int m = (l+r)/2;
        if (p[m] == x) return m;
        if (p[m] > x) r = m-1;
        else l = m+1;
    }
    return -1;
}

bool ok(vector<int> a, int k, int x){ //n=6, k=4, x=4, a={1,2,3,4,5,6}
    int n = (int) a.size(); 
    int s = 0;
    int z = 0;
    while (n-z >= k){
        sort(a.rbegin(), a.rend());
        int g = 0;
        for (int i = 0; i < n && g < k; i++){
            if (a[i] > 0){
                g++;
                a[i]--;
                if (a[i] == 0) z++;
            }
        }
        if (g == k) s++;
    }
    return s >= x;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi h(n);
    forn cin >> h[i];
    sort(h.begin(), h.end());
    ll ans = 0;
    if (k >= n) ans = 0;
    else{
        for (int i = 0; i < n-k; i++){
            ans += h[i];
        }
    }
    cout << ans << '\n';
}

int main(){
    //init();

    ios::sync_with_stdio(false);
    cin.tie(0);

    //ll t; cin >> t; while (t--)
        solve();
    return 0;
}
