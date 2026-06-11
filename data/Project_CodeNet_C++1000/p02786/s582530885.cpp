#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

ll solve(ll x){
    if(x == 1) return 1;
    return solve(x / 2) * 2 + 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll h;
    cin >> h;
    cout << solve(h);

    return 0;
}
