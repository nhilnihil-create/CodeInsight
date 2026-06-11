#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    int A[N];
    rep(i,N) {
        int a;
        cin >> a;
        A[i] = a;
    }
    map<ll,ll> S,T;

    rep(i,N) {
        ll a,b;
        a = i+1+A[i];
        b = i+1-A[i];
        S[a]++;
        T[b]++;
    }

    ll ans = 0;

    for (auto tmp:S) {
        ll a = tmp.first;
        ll num = tmp.second;

        ans += T[a]*num;
    }
    cout << ans << endl;
}
