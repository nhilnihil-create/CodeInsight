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

int main(){
    int N;
    cin >> N;
    vector<int> L(N);
    for (ll i = 0; i < N; i++) {
        cin >> L[i];
    }
    ll ans = 0;
    sort(ALL(L));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if(i == j) continue;
            ans += upper_bound(ALL(L), L[i] + L[j] - 1) - lower_bound(ALL(L), abs(L[i] - L[j]) + 1);
            if(L[i] >= abs(L[i] - L[j]) + 1 && L[i] <= L[i] + L[j] - 1) ans--;
            if(L[j] >= abs(L[i] - L[j]) + 1 && L[j] <= L[i] + L[j] - 1) ans--;
        }
    }
    ans = ans / 6;
    printf("%lld\n", ans);

}