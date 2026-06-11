#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
ll a[202020],n,ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(i){
            if(a[i] < a[i-1]){
                ans += a[i-1] - a[i];
                a[i] = a[i-1];
            }
        }
    }
    cout<<ans<<'\n';
}