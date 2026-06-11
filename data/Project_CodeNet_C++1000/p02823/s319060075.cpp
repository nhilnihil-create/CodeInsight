#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans=0;
    if((b-a)%2==0){
        ans=(b-a)/2;
    }
    else {
        ans=min(a,n-b+1)+(b-a-1)/2;
    }
    cout << ans << endl;
}