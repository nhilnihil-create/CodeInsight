#include<iostream>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;
    ll a[1000010];
    ll ans=0;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=1;i<n;++i){
        if(a[i-1]>a[i]){
            ans+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}