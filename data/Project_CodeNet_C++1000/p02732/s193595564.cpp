#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define INF 1e12
const int MOD = 1000000007;
typedef pair<ll,ll> P;

ll comb2(ll n){
    ll ans = 0;
    ans = n * (n - 1) / 2;
    return ans;
}

int main(void){
    ll N,sum = 0;
    cin >> N ;
    vector<ll> A(N+10);
    vector<ll> bucket(N+10,0);
    REP(i,N){
        cin >> A[i];
        A[i]--;
        bucket[A[i]]++; 
    }
    // すべての組み合わせ
    REP(i,N){
        sum += comb2(bucket[i]);
    }
    REP(i,N){
        ll ans = sum;
        ans -= comb2(bucket[A[i]]);     // sum - A[i]_C_2       全体からA[i]の組み合わせを引く
        ans += comb2(bucket[A[i]] - 1); // sum + (A[i]-1)_C_2　 A[i]の組み合わせを再計算し，結果に加える
        cout << ans << endl; 
    }
    return 0;
}