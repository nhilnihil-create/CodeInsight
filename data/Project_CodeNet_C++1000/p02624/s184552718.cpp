#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        int k = n/i;
        ans += (ll)k * ((ll)k+1LL) / 2LL * i;
    }
    cout<<ans<<endl;
    return 0;
}