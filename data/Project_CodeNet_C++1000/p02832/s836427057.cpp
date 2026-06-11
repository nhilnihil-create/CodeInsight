#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N; cin>>N;
    ll count=1,ans=0,m=N;
    for(ll i=0;i<N;i++){
        ll a; cin>>a;
        m=min(m,a);
        if(a==count){
            count++;
        }else{
            ans++;
        }
    }
    if(m!=1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
}
    