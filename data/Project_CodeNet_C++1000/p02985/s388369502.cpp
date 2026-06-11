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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N, 0);
    ll c, d;
    for (int i = 0; i < N-1; i++) {
        cin >> c >> d;
        c--;
        d--;
        A[c]++;
        A[d]++;
    }
    ll ans;
    if(N == 1){
        printf("%lld\n", K);
        return 0;
    }
    ans = K * (K-1) % MOD;
    for (int i = 0; i < N; i++) {
        for (int j = 2; j <= A[i]; j++) {
            ans = ans * (K-j) % MOD;
        }
    }
    printf("%lld\n", ans);

}