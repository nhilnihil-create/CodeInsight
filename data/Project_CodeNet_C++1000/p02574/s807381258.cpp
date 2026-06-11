#include <bits/stdc++.h>
using namespace std;
typedef int ll;
const ll N=1e6+5;
ll spf[N],n;
map< ll , ll > mp;
void init(){
    for(ll i=2;i<N;i+=2)spf[i]=2;
    for(ll i=3;i<N;i+=2)spf[i]=i;
    for(ll i=3;i*i<N;i+=2){
        if(spf[i]!=i)continue;
        for(ll j=i*i;j<N;j+=i)if(spf[j]==j)spf[j]=i;
    }
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    ll g=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll x;cin>>x;
        g = __gcd(g,x);
        ll prv=-1;
        while(x>1){
            if(spf[x]!=prv)mp[spf[x]]++;
            prv=spf[x];
            x/=spf[x];
        }
    }

    bool f=1;
    for(auto &ele:mp)if(ele.second>1)f=0;
    //for(auto &ele:mp)cout<<ele.first<<" "<<ele.second<<endl;
    if(f)return cout<<"pairwise coprime" , 0;

    if(g==1)cout<<"setwise coprime";
    else cout<<"not coprime";
}



