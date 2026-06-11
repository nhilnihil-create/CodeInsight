#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl

int main(){
    ll H, W; cin>>H>>W;
    ll ans=H*W/2;
    ll ans2=ans+1;
    if(H==1 || W==1){
        cout<<"1"<<endl;
    }
    else if(H*W%2==0){
        cout<<ans<<endl;
    }else{
        cout<<ans2<<endl;
    }
}
