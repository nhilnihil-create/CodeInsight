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
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; i++) {
        cin >> H[i];
    }
    ll m = 0;
    ll cnt = 0;
    for (ll i = 1; i < N; i++) {
        if(H[i-1] >= H[i]){
            cnt++;
        }
        else{
            m = max(cnt, m);
            cnt = 0;
        }
    }
    m = max(cnt, m);
    printf("%lld\n", m);
}