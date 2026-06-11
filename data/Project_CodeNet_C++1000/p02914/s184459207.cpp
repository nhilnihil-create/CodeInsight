#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

int main(){
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];
    ll e[61], sum[60];
    vector<int> vec;
    e[0] = 1;
    rep(i, 60) e[i+1] = 2*e[i];
    rep(i, 60){
        sum[i] = 0;
        rep(j, N){
            if(A[j]%e[i+1] >= e[i]) sum[i]++;
        }
        if(sum[i]%2 == 1) vec.push_back(i);
    }
    rep(i, vec.size()){
        int k = vec[i];
        rep(j, N){
            if(A[j]%e[k+1] >= e[k]) A[j] ^= e[k]; 
        }
    }
    for(int i = 59; i >= 0; i--){
        int k = N;
        rep(j, N){
            if(A[j]<e[i+1] && A[j]>=e[i]){
                k = j;
                break;
            }
        }
        if(k == N) continue;
        rep(j, N){
            if(A[j]%e[i+1] >= e[i] && j!=k){
                A[j] ^= A[k];
            }
        }
    }
    ll ans1 = 0, ans2 = 0;
    rep(i, vec.size()) ans1 += e[vec[i]];
    rep(i, N) ans2 ^= 2*A[i];
    cout << ans1 + ans2 << endl;
}