#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int k, n;
    cin>>k>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int ans = INT_MIN;
    for(int i = 0; i < n ; i++){
        if(i == n-1){
            ans = max(ans, k - a[i] + a[0]);
        }else
        {
            ans = max(ans, abs(a[i] - a[i+1]));
        }
        // cout<<i<<" "<<ans<<" "<<a[i]<<endl;
    }
    cout<<k-ans;
    return 0;
}