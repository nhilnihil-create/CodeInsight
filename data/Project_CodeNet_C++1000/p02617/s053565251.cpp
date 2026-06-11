#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll i = 1;i<=n;i++){
        ans+=i*(n-i+1);
    }
    ll a,b;
    for(int i = 0;i<n-1;i++){
        cin>>a>>b;
        if(b<a)swap(a,b);
        ans-=a*(n-b+1);
    }
    cout<<ans;
}