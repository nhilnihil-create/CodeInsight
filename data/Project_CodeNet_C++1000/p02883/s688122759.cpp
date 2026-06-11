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

bool f(vector<ll> &F, vector<ll> &A, ll X, ll K, ll N){
    vector<ll> B(N);
    for (ll i = 0; i < N; i++) {
        B[i] = X / F[i];
    }
    ll tmp = 0;
    for (ll i = 0; i < N; i++) {
        tmp += max(A[i] - B[i], zero);
    }
    if(tmp <= K){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), F(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N; i++) {
        cin >> F[i];
    }
    sort(ALL(A), greater<ll> ());
    sort(ALL(F));

    ll ng = -1;
    ll ok = 100000000000000;
    while(ng + 1 < ok){
        ll mid = (ok + ng) / 2;
        if(f(F, A, mid, K, N)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    printf("%lld\n", ok);

}