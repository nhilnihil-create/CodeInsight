#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(a%b,b);
}

vector<pair<ll, ll>> prime_fac(ll N){
    vector<pair<ll, ll>> res;
    for(ll a = 2; a*a <= N; a++){
        if (N%a != 0) continue;
        ll ex = 0;

        while(N%a == 0){
            ex++;
            N /= a;
        }

        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    ll A, B;
    cin >> A >> B;

    vector<pair<ll, ll>> res;
    res = prime_fac(gcd(A, B));
    cout << SIZE(res) + 1 << endl;
}