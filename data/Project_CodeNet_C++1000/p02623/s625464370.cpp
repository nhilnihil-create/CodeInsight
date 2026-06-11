#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    int n,m,k,ans=0;
    cin >> n >> m >> k;
    int a[n],b[m];
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    long Sa[n+1],Sb[m+1];
    Sa[0]=0;Sb[0]=0;
    rep(i,n) Sa[i+1] = Sa[i]+a[i];
    rep(i,m) Sb[i+1] = Sb[i]+b[i];
    rep(i,n+1){//Aを何番目まで読むか
        long cur = k-Sa[i];
        if(cur<0) continue;
        else{
            int ok = -1,ng = m+1;
            while(ng-ok>1){
                int mid = (ok+ng)/2;
                if(Sb[mid]<=cur) ok = mid;
                else ng = mid;
            }
            ans = max(ans,i+ok);
        }
    }
    cout << ans << endl;
}