#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

ll a,b,c,k;

void solve(){

    cin >> a >> b >> c >> k;

    ll ans = 0;

    if(k > a) ans += a;
    else{
        ans+= k;
        goto END;
    } 

    k = k-a;
    if(k > b) k-=b;
    else{
        goto END;
    }

    ans -= k;


    END:
    cout << ans << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}