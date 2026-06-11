#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll N;
    cin>>N;
    vector<ll> pos(N,0);
    for(ll i=0;i<N;i++){
        ll curr;
        cin>>curr;
        curr--;
        pos[curr]=i;
    }
    multiset<ll> ms;
    ms.insert(-1);
    ms.insert(-1);
    ms.insert(N);
    ms.insert(N);
    ll ans=0;
    for(ll i=N-1;i>=0;i--){
        ll curr=pos[i];
        ms.insert(curr);
        auto it=ms.find(curr);
        it--;
        ll p1 = *it;
        it--;
        ll p2 = *it;
        it++;it++;it++;
        ll n1 = *it;
        it++;
        ll n2 = *it;
        ll x=i+1;
        ll count=(n2-n1)*(pos[i]-p1);
        count+=(p1-p2)*(n1-pos[i]);
        ans+=(x*count);
    }
    cout<<ans<<endl;
    return 0;
}
