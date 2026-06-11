#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N,K;
    cin >> N >> K ;
    vector<ll> A(N),b(N+1);
    rep(i,N)cin >> A[i];
    rep(i,N)b[i+1] += b[i] + A[i];
    map<ll,ll> mp;
    ll ans = 0;
    for(int i = 0 ;i <= N;i++){
        // b[i] - i == b[j] - j になると嬉しい
        if(i>=K)mp[(b[i-K]-i+K)%K]--;
        ans += mp[(b[i]-i)%K];
        mp[(b[i]-i)%K]++;
    }
    cout << ans << endl;
}