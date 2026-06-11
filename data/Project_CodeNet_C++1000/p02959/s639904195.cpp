#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n; cin >> n;
    vector<int> a(n+1), b(n);
    rep(i,n+1) cin >> a[i]; rep(i,n) cin >> b[i];
    ll ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if(b[i] >= a[i+1]){
            ans += a[i+1];
            b[i] -= a[i+1];
        }
        else{
            ans += b[i]; 
            b[i] = 0;
        }
        if(a[i] >= b[i]){
            ans += b[i];
            a[i] -= b[i];
        }
        else { 
            ans += a[i];
            a[i] = 0;
        } 
        a.pop_back();
    }
    cout << ans << endl;
    return 0;
}