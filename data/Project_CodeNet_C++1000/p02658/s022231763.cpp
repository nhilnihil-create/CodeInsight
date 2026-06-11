#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin>>n;
    ll ans=1,x;
    vector<ll> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        ans*=a[i];
        if(a[i]==0){
            cout<<0<<endl;
            return 0;
        }
    }
    x=ans;
    for(int i=n-1;i>=0;--i){
        if(x==0){
            cout<<-1<<endl;
            return 0;
        }
        x/=a[i];
    }
    if(x!=1||ans>1000000000000000000)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}