#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for(ll i = a; i < (ll)(b); i++)

#define ALL(x) (x).begin(), (x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

using namespace std;
using ll = long long;
using vel = vector<ll>;
using ves = vector<string>;
using veb = vector<bool>;
using qul = queue<ll>;

void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}

int binary_search(ll x, vel a){
    auto ite = lower_bound(ALL(a), x);
    if(ite != a.end() && *ite == x) {
        return ite - a.begin() ;
    } else {
        return -1;
    }

}

ll modpow(ll a, ll n, ll mod) {
    if(n == 0)
        return 1;
    if(n == 1)
        return a % mod;
    if(n % 2 == 1)
        return (a * modpow(a, n - 1, mod)) % mod;
    ll t = modpow(a, n / 2, mod);
    return (t * t) % mod;
}

int main() {
    ll N, K, sum = 0, sum2 = 0, next, count = 0, ans, num, num2,  m_l, m_l2;
    cin >> N >> K;
    vel P(N), C(N), check(N);
    REP(i, N) cin >> P[i];
    REP(i, N) cin >> C[i];
    
    bool flag = false;
    ans = C[0];
    REP(i,N){
        count = 0;
        next = i;
        sum = 0;
        m_l = C[next];
        m_l2 = C[next];
        REP(j,N){
            sum += C[next];
            next = P[next]-1;
            ans = max(ans, sum);
            m_l2 = max(m_l2, sum);
            count++;
            if(j+1 >= K || next == i)
                break;
        }

        next = i;
        sum2 = 0;
        REP(j, K%count) {
            sum2 += C[next];
            next = P[next]-1;
            m_l = max(m_l, sum2);
        }



        if(sum >= 0){
            if(K%count==0) m_l = 0;
            num = K/count * sum + m_l;
            num2 = (K/count - 1) * sum  + m_l2;
            num = max(num, num2);
            ans = max(ans, num);
        } else {
            ans = max(ans, m_l);
        }
    }

    cout << ans << endl;

    return 0;
}