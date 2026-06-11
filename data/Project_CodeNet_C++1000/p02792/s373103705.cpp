#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll c[10][10];
ll ans;
int main(void){
    ll n; cin>>n;
    for(int i=1;i<=n;i++){
        ll k=i%10;
        ll l=i;
        while(l>=10){
            l=l/10;
        }
        c[k][l]++;
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=c[i][j]*c[j][i];
        }
    }
    cout<<ans<<endl;
    
}

