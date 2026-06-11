#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if(n%2==1){
        cout << "0" << "\n";
        return 0;
    }

    ll cnt=0;
    ll div=10;
    while(div<=n) {
        ll tmp=n/div;
        cnt+=tmp;
        div*=5;
    }
    cout << cnt << "\n";

    return 0;
}