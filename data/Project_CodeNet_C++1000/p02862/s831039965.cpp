#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int MAX = 1010000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {// テーブルを作る前処理
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll modcomb(ll n,ll k){//二項係数計算
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll X,Y;
    string S;
    cin >> X>>Y;

    /*ll dp[1000001][1000001];

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    if(!((X+Y)%3==0)){
        cout << 0 << endl;
    }
    else {
        for (ll i = 2; i < N; i++)
        {
            for (ll j = 0; j < 3*i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j - 2];
            };
        }
    }*/
    /*if((X+Y)%3==0){
        int num = (X + Y) / 3;
        vector<vector<ll>> v(num + 1, vector<ll>(num + 1, 0));
        comb(v);
        
        cout << (v[num][max(X, Y) - num])%MOD  << endl;
    }
    else{
        cout << 0 << endl;
    }*/


    if((X+Y)%3==0){
        COMinit();
        ll a = (2 * X - Y) / 3;
        ll b = (2 * Y - X) / 3;
        //cout << a << " " << b << endl;
        cout << modcomb(a + b, a) << endl;
    }
    else{
        cout << 0 << endl;
    }
}
