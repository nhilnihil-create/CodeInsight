#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int n,k,ng = 0 ,ok = 1e9;
    cin >> n >> k;
    int a[n];
    rep(i,n) cin >> a[i];
    while(ok-ng>1){
        int mid = (ok+ng)/2,cnt=0;
        rep(i,n) cnt += (a[i]-1)/mid;  
        if(cnt<=k) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}