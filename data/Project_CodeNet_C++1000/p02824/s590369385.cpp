#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N+1);
    A[0] = INF;
    for (ll i = 1; i <= N; i++) {
        cin >> A[i];
    }   

    sort(ALL(A), greater<ll> ());

    vector<ll> S(N+1);
    S[0] = 0;
    for (ll i = 1; i < N+1; i++) {
        S[i] = A[i] + S[i-1];
    }

    ll ans = P;

    for (ll k = P+1; k < N+1; k++) {
        if(A[k] + M < A[P]){
            break;
        }
        if(M*N + (k-P) * A[k] - S[k-1] + S[P-1] >= M*V){
            ans++;
        }
    }
    printf("%lld\n", ans);



}