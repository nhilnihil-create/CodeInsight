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
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    ll S;
    S = 0;
    for (int i = 0; i < N; i++) {
        S += A[i];
    }

    vector<int> D;
    for (ll i = 1; i*i <= S; i++) {
        if(S % i == 0){
            if(i * i != S){
                D.push_back(i);
                D.push_back(S / i);
            }
            else{
                D.push_back(i);
            }
        }
    }

    ll ans = 1;
    ll L = D.size();

    vector<ll> B(N);
    ll a;
    ll k;
    ll tmp;
    for (int i = 0; i < L; i++) {
        a = D[i];
        for (int j = 0; j < N; j++) {
            B[j] = A[j] % a;
        }
        k = 0;
        for (int j = 0; j < N; j++) {
            k += B[j];
        }
        k = k / a;
        sort(ALL(B));

        tmp = 0;
        for (int j = 0; j < N-k; j++) {
            tmp += B[j];
        }
        for (int j = N-k; j < N; j++) {
            tmp += (a - B[j]);
        }

        if(tmp <= 2*K){
            ans = max(ans, a);
        }


    }

    printf("%lld\n", ans);

}