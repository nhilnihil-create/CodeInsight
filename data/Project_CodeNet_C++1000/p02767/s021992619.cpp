#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = 1e9;
    for(int i=1; i<=100; i++){
        int now = 0;
        rep(j,n){
            now += (x[j]-i)*(x[j]-i);
        }
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}