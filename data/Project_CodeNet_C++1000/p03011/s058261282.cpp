#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    int p,q,r; cin >> p >> q >> r;
    int ans = p+q;
    ans = min(ans,p+r);
    ans = min(ans,q+r);
    cout << ans << endl;
}