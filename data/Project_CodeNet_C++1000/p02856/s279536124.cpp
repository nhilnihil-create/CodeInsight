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
    ll M;
    cin >> M;
    ll d, c;
    ll S = 0;
    ll k = 0;
    for (int i = 0; i < M; i++) {
        cin >> d >> c;
        k += c;
        S += d*c;
    }
    printf("%lld\n", (S-1)/9 + k-1);

}