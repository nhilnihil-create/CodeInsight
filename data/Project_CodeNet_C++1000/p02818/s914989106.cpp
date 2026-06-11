#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair



int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    ll t, a;
    if (A > K) {
        t = A - K;
        a = B;
    } else if (A + B > K) {
        t = 0;
        a = A + B - K;
    } else {
        t = 0;
        a = 0;
    }
    printf("%lld %lld\n", t, a);
    return 0;
}