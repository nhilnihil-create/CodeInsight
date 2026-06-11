#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long con=0ll;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        if(u>v){
            swap(u,v);
        }
        con+=1ll*u*(n-v+1ll);
    }
    long long ans=0ll;
    for(int i=n;i>0;i--){
        ans+=1ll*((i)*(i+1ll))/2ll;
    }
    //cout<<ans<<" "<<con<<endl;
    ans-=con;
    cout<<ans<<endl;
    return 0;
}