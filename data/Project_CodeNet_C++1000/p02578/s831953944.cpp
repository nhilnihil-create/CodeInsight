#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    long long ans = 0;
    int maxi = 0;
    rep(i,n){
        maxi = max(maxi,a[i]);
        int Bi = maxi;
        ans += Bi - a[i];
    }

    cout << ans << endl;

    return 0;


}