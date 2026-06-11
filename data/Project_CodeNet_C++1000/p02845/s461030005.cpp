#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;


int main(){
    ll N; cin >> N;
    ll Max=0;
    vector<ll> A(N); for(int i = 0; i < N; i++) {cin >> A[i]; Max = max(Max, A[i]);}
    vector<int> Count(N), Ans(N);
    for(int i = 0; i < N; i++) Ans[i]++;
    for(int i = 0; i < N; i++){
        ll x = A[i];
        if(x == 0){
            Ans[x] *= (3-Count[x]);
            Count[x]++;
        }
        else{
            Ans[x] *= (Count[x-1] - Count[x]);
            Count[x]++;
        }
    } 
    ll ans = 1;
    for(int i = 0; i <= Max; i++) { 
        ans *= Ans[i]; ans %= MOD;
    }
    cout << ans << endl;
}