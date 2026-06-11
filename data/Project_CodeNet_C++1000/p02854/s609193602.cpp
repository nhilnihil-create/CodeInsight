#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    } 
    
    ll ans=sum,t=0;
    for(int i=0;i<n;i++){
        t+=a[i];
        ans=min(ans,abs(t-(sum-t)));
    }
    cout<<ans<<endl;
}