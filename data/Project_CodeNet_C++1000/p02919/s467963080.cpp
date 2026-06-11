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
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> ind(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
        ind[P[i]] = i;
    }
    multiset<int> S;
    S.insert(-1);
    S.insert(-1);
    S.insert(N);
    S.insert(N);
    S.insert(ind[N-1]);

    ll a,b,c,d;
    ll ans = 0;
    for (int i = N-2; i >= 0; i--) {
        S.insert(ind[i]);
        auto itr = S.lower_bound(ind[i]);
        itr--;
        b = *itr;
        itr--;
        a = *itr;
        itr++; itr++; itr++;
        c = *itr;
        itr++;
        d = *itr;

        ans += (b-a) * (c - ind[i]) * (i+1);
        //printf("%lld %d\n", (b-a) * (c - ind[i])+(d-c) * (ind[i] - b) * i, i);
        ans += (d-c) * (ind[i] - b) * (i+1);
    }

    printf("%lld\n", ans);
    


}