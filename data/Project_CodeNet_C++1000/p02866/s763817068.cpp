#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;
ll mod=998244353;

int main(){
    ll n;cin>>n;
    vector<ll> v(n),dist(1e5,0);
    for(int i=0;i<n;i++)cin>>v[i];
    if(v[0]!=0){cout<<0<<endl;return 0;}
    for(int i=1;i<n;i++){
        dist[v[i]]++;
    }
    ll ans=1;
    for(int i=1;i<n;i++){
        if(v[i]==0){cout<<0<<endl;return 0;}
        if(v[i]>=2)ans=(ans*dist[v[i]-1])%mod;
        ans%=mod;
    }
    cout<<ans%mod<<endl;
}