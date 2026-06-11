#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin >> n >> k;
    int a[n+1];
    int pre[n+1];
    pre[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]++;
        pre[i] = pre[i-1] + a[i];
    }
    double ans=0;
    for(int i=k;i<=n;i++){
        double cur = pre[i] - pre[i-k];
        ans = max(ans,cur);
    }
    ans = ans/2;
    cout << fixed << setprecision(10) << ans ;
    
    return 0;
}