#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll ans = 0;
    for(ll a = 1 ; a <= 1000000 ; a++){
        for(ll b = 1 ; b <= 1000000 ; b++){
            if(a * b < n)
                ++ans;
            else
                break;
        }
    }
    //cout<<1005*1005<<" ";
    cout<<ans;
}
