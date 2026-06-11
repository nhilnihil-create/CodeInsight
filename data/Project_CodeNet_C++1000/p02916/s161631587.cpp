#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n-1);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n-1) cin >> c[i];
    int ans = 0;
    rep(i,n){
        ans += b[a[i]-1];
        if(i!=0){
            if(a[i]-1==a[i-1]){
                ans += c[a[i-1]-1];
            }
        }
    }
    cout << ans << endl;

}