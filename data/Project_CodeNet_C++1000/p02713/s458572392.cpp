#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= n; i++)
typedef long long ll;
typedef map<string, int> msi;



int gcb(int a, int b){
    if(a < b){
        int x = a;
        a = b;
        b = x;
    }
    int amari = a % b;
    if(amari == 0) return b;

    return gcb(b, amari);
}
int gcb_3(int a, int b, int c){
    return gcb(gcb(a, b), c);
}

int main(){
    int n;cin >> n;
    ll ans = 0;
    rep(i, n)rep(j, n)rep(k, n){
        ans += gcb_3(i, j, k);
    }
    cout << ans << endl;
    return 0;
}
