#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n];
    rep(i,n) cin>>p[i];

    int ans=0;
    for(int i=2; i<n; i++){
        if( (p[i-2]<p[i-1]) && (p[i-1]<p[i]) ){
            ans++;
        }
        else if( (p[i]<p[i-1]) && (p[i-1]<p[i-2]) ){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}