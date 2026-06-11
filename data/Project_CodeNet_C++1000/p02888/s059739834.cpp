#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    int n; cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(),l.end());
    reverse(l.begin(),l.end());
    ll ans = 0;
    rep(i,n-2){
        int lmax = l[i];
        for(int j=i+1; j<n-1;j++){
            if(lmax == l[j]){
                ans += n-1-j;
            } else {
                int lmin = lmax - l[j];
                for(int k=j+1; k<n; k++){
                    if(l[k] > lmin) ans++;
                    else break;
                }
            }
        }
    }
    cout << ans << endl;
}