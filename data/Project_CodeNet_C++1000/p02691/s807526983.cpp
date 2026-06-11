#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    // j-i = A[i]+A[j]
    // j-A[j] = i+A[i]
    // それぞれをハッシュに登録する
    map<ll,ll> P,M;
    rep(i,N){
        P[i+1+A[i]]++;
        M[i+1-A[i]]++;
    }
    ll ans = 0;
    rep(i,N){
        // ペアを探す
        ll tmp = 0;
        tmp += P[i+1-A[i]];
        tmp += M[i+1+A[i]];
        ans+=tmp;
    }
    cout << ans/2 << endl;
    return 0;
}