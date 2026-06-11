#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    int ans;
    if(n%2){
        int l = a[n/2];
        int r = b[n/2];
        ans = r-l+1;
    }
    else{
        int l = a[n/2]+a[n/2-1];
        int r = b[n/2]+b[n/2-1];
        ans = r-l+1;
    }
    cout << ans << endl;
    return 0;
}