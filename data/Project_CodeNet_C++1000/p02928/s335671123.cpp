#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;
const ll MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    //内部転倒数を数える
    ll p = 0;
    for (int i=0;i<N-1;i++){
        for (int j=i+1;j<N;j++){
            if (A[i]>A[j]) {
                p++;
            }
        }
    }
    //外部転倒数を数える
    ll q=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (A[j] > A[i]){
                q++;
            }
        }
    }
    //ll ans = (K*p + K*(K-1)/2%MOD*q)%MOD;
    ll ans = ((K*p)%MOD + ((K*(K-1)/2)%MOD*q)%MOD)%MOD;
    cout << ans << "\n";
}