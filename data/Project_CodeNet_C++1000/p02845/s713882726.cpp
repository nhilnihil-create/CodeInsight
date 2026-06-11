#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD =1000000007;

int main() {
    ll N;
    cin >> N;
    ll num[] ={0,0,0};
    ll ans =1;
    for(int i=0;i<N;i++){
        ll A;
        cin >> A;
        set<ll> candidates;
        for(int j=0;j<3;j++){
            if(num[j] == A){
                candidates.insert(j);
            }
        }
        int p =*candidates.begin();
        ans*= (candidates.size());
        ans %= MOD;
        num[p]++;
    }
    cout << ans << endl;
    return 0;
}