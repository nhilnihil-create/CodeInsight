#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll N,K,sum = 0;
vector<ll> A;
vector<ll> B;

bool F(ll x){
    B = vector<ll>();
    ll SUM = 0,NOW = 0,NOW2 = 0;
    rep(i,N){
        B.push_back(A[i] % x);
        SUM += x - B[i];
    }
    sort(ALL(B));
    ll res = INF;
    rep(i,N){
        NOW += B[i];
        NOW2 += x - B[i];
        ll A = NOW,B = SUM - NOW2;
        res = min(res,max(A,B));
    }
    return res <= K;
}

int main(){
    cin >> N >> K;
    rep(i,N){
        ll a;cin >> a;
        A.push_back(a);
        sum += a;
    }
    ll ans = 0;
    for(ll i = 1;i * i <= sum;i++){
        if(sum % i == 0){
            if(F(i)) ans = max(ans,i);
            if(F(sum / i)) ans = max(ans,sum / i);
        }
    }
    cout << ans << endl;
}
