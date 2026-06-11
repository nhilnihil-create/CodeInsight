#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int MAX = 510000;
//const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];

/*void modcombinit()
{ // テーブルを作る前処理
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long modcomb(long long n, long long k)
{ //二項係数計算
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}*/

long long int ext_gcd(long long int a, long long int b, long long int &x, long long int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long int q = a / b;
    long long int g = ext_gcd(b, a - q * b, x, y);
    long long int z = x - q * y;
    x = y;
    y = z;
    return g;
}

//aとmは互いに素, a^(-1) mod m
long long int modinv(long long int a, long long int m)
{
    long long int x, y;
    ext_gcd(a, m, x, y);
    x %= m;
    if (x < 0)
        x += m;
    return x;
}

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N,a,b;
    string S;
    cin >> N>>a>>b;

    vector<ll> vec(200000+100);



    REPS(i,200000){
        ll tmp = modinv(i, MOD);
        if(i>1){
            vec.at(i) = ((vec.at(i - 1) * (N + 1 - i))%MOD) * tmp % MOD;
        }
        else{
            vec.at(i) = N * tmp % MOD;
        }
    }

    ll all = (modpow(2, N, MOD)-1) % MOD;

    ll na = vec.at(a);
    ll nb = vec.at(b);

    //cout << all << " " << na << " " << nb << endl;

    ll ans = all - na - nb;

    if(ans<0){
        while(ans<0){
            ans += MOD;
        }
    }
    else{
        ans % MOD;
    }
    cout << ans % MOD << endl;
}
