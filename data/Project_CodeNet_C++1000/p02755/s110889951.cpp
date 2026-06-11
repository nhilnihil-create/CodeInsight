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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll A,B;
    string S;
    cin >> A>>B;

    bool flag = true;

    REPS(i,10000){
        double A_d = (double)i * 0.08;
        double B_d = (double)i * 0.1;

        ll A_l = (ll)A_d;
        ll B_l = (ll)B_d;
        if(A_l==A&&B_l==B&&A<=100&&B<=100&&1<=A&&1<=B){
            cout << i << endl;
            flag = false;
            break;
        }
    }
    if(flag){
        cout << -1 << endl;
    }
}
