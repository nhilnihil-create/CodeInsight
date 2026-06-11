#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    ll N;
    cin >> N;
    ll ans = INF;
    for (ll i = 1; i * i <= N;i++){
        if(N%i==0){
            ans = min(ans, i - 1 + (N / i) - 1);
        }
    }
    cout << ans << endl;
}