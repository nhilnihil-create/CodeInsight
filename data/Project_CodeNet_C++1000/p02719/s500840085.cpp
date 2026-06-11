#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a,b;
    cin >> a >> b;
    if(a > b) {
        a -= (a/b)*b;
    }
    cout << min(a,b-a) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)
        solve();
    return  0;
}
