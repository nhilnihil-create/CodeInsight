#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll x;
    cin >> x;
    ll ans=0;
    bool judge=true;
    while(judge){
        ans++;
        if(ans*x%360==0){
            break;
        }
    }
    cout << ans << endl;
}