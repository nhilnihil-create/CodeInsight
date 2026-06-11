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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N,M;
    string S;
    cin >> N>>M;
    vector<ll> a(M+2);
    REPS(i, M)
        cin >> a.at(i);

        a.at(0) = -1;
        a.at(M + 1) = N+1;

        bool flag = true;
        REPS(i,M-1){
            if(a.at(i)+1==a.at(i+1)){
                flag = flase;
            }
        }

        /*REP(i,M+2){
            cout << i << ":" << a.at(i) << endl;
        }*/

        vector<ll> b(M+1);

        REP(i,M+1){
            b.at(i) = a.at(i + 1) - a.at(i) - 2;
            //cout << i << " " << b.at(i) << endl;
        }

        ll dp[N+10];

        dp[1] = 1;
        dp[0] = 1;

    REP(i,N){
        dp[i + 2] = dp[i] + dp[i + 1];
        dp[i + 2] %= MOD;
    }

    ll ans = 1;

    if(flag){
    REP(i,M+1){
        //cout << i<<" "<<b.at(i) <<" "<< dp[b.at(i)] << endl;
        ans *= dp[b.at(i)];
        //cout << ans << endl;
        ans %= MOD;
    }
    cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }
}
