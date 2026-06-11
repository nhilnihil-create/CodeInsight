#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main(){
    ll N, M; cin >> N >> M;
    vector<ll> b(N);
    for (ll i = 0; i < N; i++) {
        cin >> b[i]; b[i] = b[i] / 2;
    }   

    if(N == 1){
        printf("%lld\n", M / b[0] - M / (2*b[0]));
        return 0;
    }

    ll L = lcm(b[0], b[1]);
    for (ll i = 2; i < N; i++) {
        L = lcm(L, b[i]);
        if(L > M){
            printf("0\n");
            return 0;
        }
    }

    ll C = M / L;

    ll D = M / (2*L);

    for (ll i = 0; i < N; i++) {
        if( (L / b[i]) % 2 == 0 ){
            D = C;
        }
    }

    printf("%lld\n", C-D);
    


}