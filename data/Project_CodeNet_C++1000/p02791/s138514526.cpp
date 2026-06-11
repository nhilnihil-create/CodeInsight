#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    int l = 1e9;
    int ans = 0;
    rep(i,n){
        int p;
        cin >> p;
        l = min(l,p);
        if(p <= l) ans++;
    }
    cout << ans << endl;
    return 0;
}