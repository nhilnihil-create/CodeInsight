#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9+7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A,B,C,D,E,F,G,H,I,J,K,L,N,M,O,P,Q,R,S,T,U,V,W,X,Y,Z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;

typedef long long ll;
typedef pair<ll, ll> Pa;

ll dp[100001];
bool live[100001];

int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    P = t1*(a1-b1);
    Q = t2*(a2-b2);
    if(P > 0) P *= -1, Q *= -1;
    if(P + Q < 0) cout << 0;
    else if(P + Q == 0) cout << "infinity";
    else {
        S = (-1*P)/(P+Q);
        T = (-1*P)%(P+Q);
        if(T == 0) cout << S*2;
        else cout << S*2+1;
    }                                                                                                
}
