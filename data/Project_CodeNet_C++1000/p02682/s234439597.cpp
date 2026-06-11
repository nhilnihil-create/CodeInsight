#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,k;
    cin >> a >> b >> c >> k ;
    int ans = 0;
    ans += min(a,k);
    k -= min(a,k);
    k -= min(b,k);
    ans -= k;
    cout << ans << endl;
}