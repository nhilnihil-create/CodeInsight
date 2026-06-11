#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,m;
    cin>>n;
    m=n;
    vector<ll> v;
    map<ll,ll> mp;
    for(int i=2;i<=sqrt(m);i++){
        if(n%i==0){
            if(v.empty()){
                v.push_back(i);
            }else{
                if(*prev(v.end())!=i){
                    v.push_back(i);
                }
            }
            mp[i]++;
            n/=i;
            i--;
        }
    }
    if(n!=1){
        v.push_back(n);
        mp[n]++;
    }
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    if(n==m){
        cout<<1<<endl;
        return 0;
    }
    ll ans=0;
    for(auto a:v){
        ll c=mp[a];
        for(int i=2;i<100;i++){
            if(i*(i+1)/2<=c)continue;
            ans+=i-1;
            break;
        }
    }
    cout<<ans<<endl;
}