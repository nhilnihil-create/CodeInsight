#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb                push_back
#define mp                make_pair
#define ll                long long
#define ld                long double
#define pii               pair <ll, ll>
#define piii              pair <ll, pii>
#define F                 first
#define S                 second

#define newline           printf("\n")
#define minusone          printf("-1\n")
#define zeroo             printf("0\n")
#define scl1(a)           scanf("%lld", &a)
#define scl2(a, b)        scanf("%lld %lld", &a, &b)
#define scl3(a, b, c)     scanf("%lld %lld %lld", &a, &b, &c)
#define prl1(a)           printf("%lld\n", a)
#define prl2(a, b)        printf("%lld %lld\n", a, b)
#define ssl1(s)           scanf(" %[^\n]", s)
#define scd1(a)           scanf("%lf", &a)
#define scd2(a, b)        scanf("%lf %lf", &a, &b)
#define prd(a)            printf("%lf\n", a)
#define prld(a)           printf("%Lf\n", a)
#define prcase(cs)        printf("Case %lld: ", cs)
#define cin1(a)           cin >> a
#define cin2(a, b)        cin >> a >> b
#define cin3(a, b, c)     cin >> a >> b >> c
#define cin4(a, b, c, d)  cin >> a >> b >> c >> d
#define cot1(a)           cout << a << "\n"
#define cot2(a, b)        cout << a << " " << b << "\n"
#define cot3(a, b, c)     cout << a << " " << b << " " << c << "\n"
#define cot4(a, b, c, d)  cout << a << " " << b << " " << c << " " << d << "\n"
#define cotline           cout << "\n"
#define cotminus          cout << "-1\n"
#define cot0              cout << "0\n"
#define cotyes            cout << "YES\n"
#define cotno             cout << "NO\n"
#define cotcase(cs)       cout << "Case " << cs << ": "

#define reversed(s)       reverse(s.begin(), s.end())
#define asort(s)          sort(s.begin(), s.end())
#define dsort(s)          sort(s.rbegin(), s.rend())
#define all(s)            s.begin(), s.end()
#define uniq(s)           s.resize(distance(s.begin(),unique(s.begin(), s.end())))
#define found(s, x)       (s.find(x) != s.end())

#define for0(i, n)        for (i = 0; i < n; i++)
#define for1(i, n)        for (i = 1; i <= n; i++)
#define fora(i, a, b)     for (i = a; i <= b; i++)
#define forb(i, b, a)     for (i = b; i >= a; i--)
#define fori(it, s)       for(auto it = s.begin(); it != s.end(); it++)

#define FR                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ms(a, x)          memset(a, x, sizeof a)
#define bitcount(n)       __builtin_popcountll(n)

//#define pi              3.1415926536
#define pi                acos(-1)

const ll INF = LLONG_MAX;
const ll SZ = 4e5+5;
const ll mod = 1e9+7;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, m;
ll a[SZ];
//ll b[SZ];
unordered_map <ll, ll, custom_hash> f;

bool st[SZ];
vector <ll> prime;
void sieve() {
    ll i, j;

    for(i = 2; i*i < SZ; i++) {
        if(!st[i]) {
            for(j = i*i; j < SZ; j += i) st[j] = 1;
        }
    }

    prime.pb(2);
    for(i = 3; i < SZ; i += 2) if(!st[i]) prime.pb(i);
}

void factorize(ll x) {
    for(ll i = 0; i < prime.size() && prime[i]*prime[i] <= x; i++) {
        if(x%prime[i] == 0) {
            ll c(0);
            while(x%prime[i] == 0) {
                c++;
                x /= prime[i];
            }
            f[prime[i]] = max(f[prime[i]], c);
        }
    }

    if(x > 1) {
        f[x] = max(f[x], 1LL);
    }
}

ll bigmod(ll x, ll y) {
    if(y == 0) return 1;

    ll res = bigmod(x, y/2);
    res = (res * res);
    if(y%2 == 1) res = (res * x);

    return res;
}


int main() {
    sieve();
    ll cs = 0, tc = 1, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0, t = 0;
//    ll a, b, d;
    string s, s1, s2;

    cin2(n, m);
    for1(i, n) cin1(a[i]);

    c = 0, x = a[1];
    while(x%2 == 0) {
        x /= 2;
        c++;
    }
    fora(i, 2, n) {
        t = 0, x = a[i];
        while(x%2 == 0) {
            x /= 2;
            t++;
        }
        if(t != c) {
            cot0;
            return 0;
        }
    }

    for1(i, n) {
        factorize(a[i]/2);
    }

    k = 1;
    for(auto p: f) {
        x = bigmod(p.F, p.S);
        if(k > (m/x)) {
            cot0;
            return 0;
        }
        k *= x;
    }

    ans = (m / k) - ((m/k) / 2);
    cot1(ans);


    return 0;
}

