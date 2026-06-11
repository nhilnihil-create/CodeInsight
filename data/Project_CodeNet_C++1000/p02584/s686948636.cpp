#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,k,d;
    cin >> x >> k >> d;
    if(x<0) x*=-1;
    if(x/d > k){
        cout << x-d*k << "\n";
    }
    else{
        int ans = x%d;
        if((k-x/d)%2) ans=d-ans;
        cout << ans << "\n";
    }
    return 0;
}