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


ll n;
unordered_map <ll, ll> m;
ll f[30];

const ll b1 = 1e4+7;
const ll b2 = 1e9+87;
const ll mod1 = 998244353;
const ll mod2 = 1e9+9;

ll pw1[SZ], pw2[SZ];
ll h1[3][SZ], h2[3][SZ];
ll szs[3];

void cal_pwr() {
    pw1[0] = pw2[0] = 1;
    for(ll i = 1; i < SZ; i++) {
        pw1[i] = (pw1[i-1] * b1) % mod1;
        pw2[i] = (pw2[i-1] * b2) % mod2;
    }
}

void build_hash(string s, ll id) {
    ll i, sz = s.size();
    szs[id] = sz;

    h1[id][0] = h2[id][0] = 0;
    for0(i, sz) {
        h1[id][i+1] = ((h1[id][i] * b1) + s[i]) % mod1;
        h2[id][i+1] = ((h2[id][i] * b2) + s[i]) % mod2;
    }
}

ll get_hash(ll l, ll r, ll id) {
    ll v1 = (h1[id][r] - (h1[id][l-1] * pw1[r-l+1])) % mod1;
    if(v1 < 0) v1 += mod1;

    ll v2 = (h2[id][r] - (h2[id][l-1] * pw2[r-l+1])) % mod2;
    if(v2 < 0) v2 += mod2;

    return ((v1 << 32LL) | v2);
}

int main() {
    FR;
    cal_pwr();
    ll cs = 0, tc = 1, x, y, z, i, j, k, g, p, q, ans = 0, sum = 0, c = 0, t = 0;
//    ll a, b, d;
    string s, s1, s2;

    cin2(n, s);

    build_hash(s, 0);

    for(ll ln = n/2; ln >= 2; ln--) {
        m.clear();

        p = get_hash(1, ln, 0);
        m[p] = 1;
        for(i = ln; i+ln-1 < n; i++) {
            j = i+ln-1;
            x = get_hash(i+1, j+1, 0);
            m[x]++;
        }

        if(m[p] > 1) {
            cot1(ln);
            return 0;
        }

        for(i = 1; i+ln-1 < n; i++) {
            j = i+ln-1;
            p = get_hash(i+1, j+1, 0);
            m[p]++;

            if(j+ln-1 < n) {
                k = j+ln-1;
                x = get_hash(j+1, k+1, 0);
                m[x]--;
            }
            x = get_hash(i, j, 0);
            m[x]--;

            if(i-ln >= 0) {
                x = get_hash(i-ln+1, i, 0);
                m[x]++;
            }

            if(m[p] > 1) {
                cot1(ln);
                return 0;
            }
        }
    }

    for0(i, n) {
        x = s[i] - 'a';
        f[x]++;
        if(f[x] > 1) {
            cot1(1);
            return 0;
        }
    }

    cot0;

    return 0;
}

