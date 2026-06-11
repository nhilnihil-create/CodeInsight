#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll N; cin>>N;
    vector<ll> H(N);
    for (ll i = 0; i < N; i++){
        cin>>H[i];
    }
    ll ans=0,cnt=0;
    ll i=0;
    while(i<N-1){
        if(H[i]>=H[i+1]){
            cnt++;
        }else{
            ans=max(ans,cnt);
            cnt=0;
        }
        i++;
    }
    ans=max(ans,cnt);
    cout<<ans<<endl;
}
    