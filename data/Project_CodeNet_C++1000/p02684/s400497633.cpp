#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i]; a[i]--;
    }
    
    ll M = 1;
    while((one<<M) < K) M++;
    
    vector<vector<int>> x(M, vector<int> (N));
    for (int i = 0; i < N; i++) {
        x[0][i] = a[i];
    }
    for (int m = 1; m < M; m++) {
        for (int i = 0; i < N; i++) {
            x[m][i] = x[m-1][x[m-1][i]];
        }
    }

    ll ans = 0;
    for (ll m = M-1; m >= 0; m--) {
        if(1 & (K>>m)){
            ans = x[m][ans];
        }
    }
    printf("%lld\n", ans+1);

}