#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll m,d;
    cin>>m>>d;
    ll ans=0;
    for(ll i=10;i<=d;i++){
        ll d1=i%10;
        ll d10=i/10;
        if(d1>=2&&d10>=2&&d1*d10<=m){
//            cout<<d1<<" "<<d10<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
}