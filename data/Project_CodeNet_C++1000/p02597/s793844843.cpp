#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string c;
    cin >> n >> c;
    int r=0;
    for(int i = 0; i < n; i++) {
        if(c[i]=='R') r++;
    }
    int w=0;
    int ans=r;
    for(int i = 0; i < n; i++) {
        if(c[i]=='W') w++;
        else r--;
        int tans=max(w,r);
        ans=min(ans,tans);
    }
    cout << ans << "\n";
    return 0;
}