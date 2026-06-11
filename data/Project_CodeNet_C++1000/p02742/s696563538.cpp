#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    cin >> h >> w;
    if(h==1 || w==1){
        cout << "1" << "\n";
        return 0;
    }
    ll ans=((h+1)/2)*((w+1)/2)+(h/2)*(w/2);
    cout << ans << "\n";
    return 0;
}