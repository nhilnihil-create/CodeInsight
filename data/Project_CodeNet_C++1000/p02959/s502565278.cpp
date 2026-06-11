#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n;
    cin >> n;
    vector <long long> a(n+1), b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];

    long long ans = 0;

    for(int i=0; i<n; i++){
        if(a[i] >= b[i]){
            ans += b[i];
        }
        else{
            ans += a[i];
            if(a[i+1] <= (b[i]-a[i])){
                ans += a[i+1];
                a[i+1] = 0;
            }
            else{
                ans += (b[i] - a[i]);
                a[i+1] -= (b[i] - a[i]);
            }
        }
    }

    cout << ans << endl;
}
