#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for(int i=m; i<n; i++)

int main(){
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if(a<b){
        rep(i, b){
            ans *= 10;
            ans += a;
        }
    }
    else{
        rep(i, a){
            ans *= 10;
            ans += b;
        }
    }
    cout << ans << endl;
}